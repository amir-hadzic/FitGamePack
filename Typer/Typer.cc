/**
*    This file is part of FitGamePack.
*
*    FitGamePack is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    FitGamePack is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with FitGamePack.  If not, see <http://www.gnu.org/licenses/>.
*
*    Author: Amir Hadzic <amir.hadzic@randomshouting.com>
*/

#include "Typer.h"

using namespace Fitgy;

namespace Typer {

Game* Game::mInstance = 0;

Game*
Game::getInstance(){
    if (mInstance == NULL){
        mInstance = new Game();
    }

    return mInstance;
}

Game::Game()
    : Application()
{
    mScore = 0;
    mCurrentWord = NULL;
    mLives = 10;
    mGameOver = false;
    mTypedLettersCount = 0;
    mScoredLettersCount = 0;
}

Game::~Game(){
    TTF_CloseFont(mWordFont);
    TTF_CloseFont(mLabelFont);
    delete mTypingSound;
}

bool
Game::init()
{
    if (Application::init() == false) {
        return false;
    }

    String basePath = executablePath();
    mDisplay->setTitle("Fitgy::Typer", "Typer");

	readWords(basePath + "/word-list.txt");

	mSplashScreen = new SplashScreen(mDisplay, basePath + "/gfx/splash.png", 2000);

	mWordFont = TTF_OpenFont((basePath + WORD_FONT).c_str(), 18);
	if (mWordFont == NULL) {
		throw Exception::FileNotFound(WORD_FONT);
	}

	mLabelFont = TTF_OpenFont((basePath + LABEL_FONT).c_str(), 22);
	if (mLabelFont == NULL) {
		throw Exception::FileNotFound(LABEL_FONT);
	}

	mImgBackground = new ImageEntity(getDisplay(), basePath + "/gfx/background.png");
	mImgBackground->position.x = 0;
	mImgBackground->position.y = 0;

	mTxtScore = new TextEntity(getDisplay(), "Score: 0", mLabelFont, Color::white());

	mTxtScore->position.x = 10;
	mTxtScore->position.y = 10;

	mTxtLives = new TextEntity(getDisplay(), "Lives: 10", mLabelFont, Color::white());
	mTxtLives->position.x = getDisplay()->getWidth() - mTxtLives->getWidth() - 10;
	mTxtLives->position.y = 10;

	mTypingSound = new Sound(basePath + "/sfx/typing.ogg", MIX_MAX_VOLUME, TYPING_CHANNEL);
	mFailSound = new Sound(basePath + "/sfx/fail.ogg", MIX_MAX_VOLUME / 2,	FAIL_CHANNEL);

	setMusic(basePath + "/sfx/signal.ogg", MIX_MAX_VOLUME/2);

	addEntity(mImgBackground);
    addEntity(mTxtScore);
    addEntity(mTxtLives);

    srand(time(NULL));
    mNextSpawnTime = getRandomSpawnTime();
    return true;
}

void
Game::render(){
    if (mSplashScreen != NULL && !mSplashScreen->isFinished()){
        mSplashScreen->onRender(mDisplay);
        return;
    }

    if (mSplashScreen != NULL){
        // Call the destructor to release all resources.
        delete mSplashScreen;
        mSplashScreen = NULL;

        music()->play();
    }

    Application::render();
}

void
Game::loop(){
    if (mSplashScreen != NULL){
        mSplashScreen->onLoop();
	} else if (mGameOver){
		Application::loop();
	} else if(!mGameOver) {
        Application::loop();

        std::vector<TyperWord*>::iterator it;
        if (mCurrentWord != NULL && mCurrentWord->isSolved()){
            it = std::find(mActiveWords.begin(), mActiveWords.end(), mCurrentWord);
            mActiveWords.erase(it);
            removeEntity(mCurrentWord);

            incrementScore();
            mCurrentWord = NULL;
        }

        // Find fallen words and delete them
        it = mActiveWords.begin();
        while(it != mActiveWords.end()){
            if (!getDisplay()->isWithinBounds((*it)->position)){
                if (mCurrentWord == (*it)){
                    mCurrentWord = NULL;
                }

                removeEntity((*it));
                it = mActiveWords.erase(it);
                mFailSound->play();
                decrementLives();
            } else {
                ++it;
            }
        }

        // See if we are supposed to spawn a word.
        // Do not spawn the word if there are already too many active words.
        bool blockSpawn = mActiveWords.size() >= (mScore / 10) + 1;
        if (SDL_GetTicks() >= mNextSpawnTime && !blockSpawn){
            spawnWord();
            mNextSpawnTime = getRandomSpawnTime();
        }

        if (mLives == 0) {
			gameOver();
		}
    }
}

void
Game::readWords(String filename){
    std::ifstream wordFile(filename.c_str());

    if (wordFile.fail()){
        throw Exception::FileNotFound(filename);
    }

    while(!wordFile.eof()){
        String word;
        std::getline(wordFile, word);

        if (word != ""){
            mWords.push_back(word);
        }
    }
}

String
Game::nextWord(){
    String word = "";

    while(word == ""){
        unsigned int randIndex = rand() % (mWords.size());
        String foundWord = mWords[randIndex];

        bool found = false;
        std::vector<TyperWord*>::iterator it = mActiveWords.begin();
        while (it != mActiveWords.end()){
            if ((*it)->getWord() == foundWord) {
                found = true;
                break;
            }
            ++it;
        }

        if (!found){
            word = foundWord;
        }
    }

    return word;
}

void
Game::spawnWord(){
    String word = nextWord();
    TyperWord* typerWord = new TyperWord(getDisplay(), word, mWordFont);

    int maxY = getDisplay()->getWidth() - typerWord->getWidth();
    typerWord->position.y = 0;
    typerWord->position.x = rand() % (maxY + 1);
    typerWord->direction = Vector::down;
    typerWord->setSpeed(getRandomSpeed());

    mActiveWords.push_back(typerWord);
    addEntity(typerWord);
}

unsigned int
Game::getRandomSpawnTime(){
    // For now we are going to always choose some random time.
    // TODO: Spawn time should be relative to the current score.

    return SDL_GetTicks() + 300 + (rand() % (1600));
}

unsigned int
Game::getRandomSpeed(){
    float calculatedMin = MIN_START_SPEED + mScore * 1.5f;
    float calculatedMax = MAX_START_SPEED + mScore * 1.5f;

	return calculatedMin + ((float)(rand() % 100) / 100) * (calculatedMax - calculatedMin);
}

void
Game::incrementScore(){
    mScore++;
    mTxtScore->setText("Score: " + intToString(mScore));
}

void
Game::decrementLives(){
	mLives--;
	mTxtLives->setText("Lives: " + intToString(mLives));
}

void
Game::gameOver() {
	mGameOver = true;

	std::vector<TyperWord*>::iterator it = mActiveWords.begin();
	while (it != mActiveWords.end()) {
		removeEntity(*it);
		++it;
	}
	mActiveWords.clear();

	music()->stop();

	TextEntity* txtGameOver = new TextEntity(getDisplay(), "Game over!", mLabelFont, Color::green());
	txtGameOver->position.x = getDisplay()->getWidth() / 2 - txtGameOver->getWidth() / 2;
	txtGameOver->position.y = getDisplay()->getHeight() / 2 - txtGameOver->getHeight() / 2;

	float accuracy = ((float)mScoredLettersCount / mTypedLettersCount) * 100;
	String accuracyInfo = "Accuracy: " + floatToString(accuracy) + "%";

	TextEntity* txtAccuracy = new TextEntity(getDisplay(), accuracyInfo, mLabelFont, Color::green());
	txtAccuracy->position.x = getDisplay()->getWidth() / 2 - txtAccuracy->getWidth() / 2;
	txtAccuracy->position.y = txtGameOver->position.y + txtGameOver->getHeight() + 10;

	addEntity(txtGameOver);
	addEntity(txtAccuracy);
}

bool
Game::onKeyDown(SDLKey sym, SDLMod mod, uint16_t unicode){
    if (mCurrentWord == NULL){
        std::vector<TyperWord*>::iterator it;
        it = mActiveWords.begin();
        while (it != mActiveWords.end()){
            if ((*it)->addLetter((char)unicode)){
                mCurrentWord = *it;
                mScoredLettersCount++;
                break;
            }

            ++it;
        }
    } else {
        if (!mCurrentWord->addLetter((char)unicode)){
            mCurrentWord = NULL;
        } else {
        	mScoredLettersCount++;
        }
    }

    mTypedLettersCount++;
    mTypingSound->play();
    return true;
}

}
