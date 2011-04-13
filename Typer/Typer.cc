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
    }

    Game::~Game(){
        TTF_CloseFont(mWordFont);
        TTF_CloseFont(mLabelFont);
        delete typingSound;
    }

    bool
    Game::init()
    {
        if (Application::init() == false) {
            return false;
        }

        mDisplay->setTitle("Fitgy::Typer", "Typer");

        try
        {
            readWords("word-list.txt");

            mSplashScreen = new Fitgy::SplashScreen(
                mDisplay, "gfx/splash.png", 2000
            );

            mWordFont = TTF_OpenFont(WORD_FONT.c_str(), 18);
            if (mWordFont == NULL) {
                throw Fitgy::Exception::FileNotFound(WORD_FONT);
            }

            mLabelFont = TTF_OpenFont(LABEL_FONT.c_str(), 22);
            if (mLabelFont == NULL) {
                throw Fitgy::Exception::FileNotFound(LABEL_FONT);
            }

            imgDanger = new Fitgy::ImageEntity(getDisplay(), "gfx/danger.png");
            imgDanger->position.x = 10;
            imgDanger->position.y = getDisplay()->getHeight();
            imgDanger->position.y -= imgDanger->getHeight() + 20;

            txtScore = new Fitgy::TextEntity(getDisplay(), "Score: 0", mLabelFont,
                                    Fitgy::Color::white());

            txtScore->position.x = 10;
            txtScore->position.y = 10;

            typingSound = new Fitgy::Sound("sfx/typing.ogg");

            setMusic("sfx/signal.ogg", MIX_MAX_VOLUME/2);
        } catch (Fitgy::Exception::FileNotFound const &e){
            Fitgy::MessageBox::show("Resource not found: " + e.getFile(), "Error",
                                Fitgy::MessageBoxInt::MessageError, Fitgy::MessageBoxInt::ButtonOK);
            return false;
        }

        addEntity(txtScore);
        addEntity(imgDanger);

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
    } else {
            Application::loop();

            // Find typed words and delete them.
            std::map<std::string, TyperWord*>::iterator it;
            it = mActiveWords.begin();
            while(it != mActiveWords.end()){
                if (it->second->isSolved()){
                    mScore++;
                    removeEntity(it->second);
                    mActiveWords.erase(it++);
                    updateScore();
                } else if (it->second->position.y - 50> getDisplay()->getWidth()) {
                    mScore--;
                    removeEntity(it->second);
                    mActiveWords.erase(it++);
                    updateScore();
                } else {
                    ++it;
                }
            }

            // See if we are supposed to spawn a word.
            if (SDL_GetTicks() >= mNextSpawnTime){
                spawnWord();
                mNextSpawnTime = getRandomSpawnTime();
            }
        }
    }

    void
    Game::restart(){

    }

    void
    Game::readWords(char* filename){
        std::ifstream wordFile(filename);

        if (wordFile.fail()){
            throw Fitgy::Exception::FileNotFound(filename);
        }

        while(!wordFile.eof()){
            std::string word;
            std::getline(wordFile, word);

            if (word != ""){
                mWords.push_back(word);
            }
        }
    }

    std::string
    Game::nextWord(){
        std::string word = "";

        while(word == ""){
            unsigned int randIndex = rand() % (mWords.size());
            std::string foundWord = mWords[randIndex];

            if (mActiveWords.find(foundWord) == mActiveWords.end()){
                word = foundWord;
            }
        }

        return word;
    }

    void
    Game::spawnWord(){
        std::string word = nextWord();
        TyperWord* typerWord = new TyperWord(getDisplay(), word, mWordFont);

        int maxY = getDisplay()->getWidth() - typerWord->getWidth();
        typerWord->position.y = 0;
        typerWord->position.x = rand() % (maxY + 1);
        typerWord->direction = Fitgy::Vector::down;
        typerWord->setSpeed(getRandomSpeed());

        mActiveWords[word] = typerWord;
        addEntity(typerWord);
    }

    unsigned int
    Game::getRandomSpawnTime(){
        // For now we are going to always choose some random time.
        // TODO: Spawn time should be relative to the current score.

        return SDL_GetTicks() + 300 + (rand() % (1501));
    }

    unsigned int
    Game::getRandomSpeed(){
        // Just take some random speed for now.
        // TODO: Speed should be relative to the current score.

        return 50 + (rand() % 200);
    }

    void
    Game::updateScore(){
        std::stringstream ss;
        ss << "Score: " << mScore;


        txtScore->setText(ss.str());
    }

    bool
    Game::onKeyDown(SDLKey sym, SDLMod mod, uint16_t unicode){
        typingSound->play();
        return true;
    }
}
