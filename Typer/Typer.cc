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
        : Fitgy::Application::Application()
    {

    }

    Game::~Game(){
        TTF_CloseFont(mWordFont);
        TTF_CloseFont(mLabelFont);
    }

    bool
    Game::init()
    {
        if (Application::init() == false) {
            return false;
        }

        mDisplay->setTitle("Fitgy::Typer", "Typer");
        readWords("word-list.txt");

        mSplashScreen = new Fitgy::SplashScreen(
            mDisplay, "gfx/splash.bmp", 2000
        );

        mWordFont = TTF_OpenFont("fonts/DroidSansMono.ttf", 18);
        mLabelFont = TTF_OpenFont("fonts/DroidSans.ttf", 22);

        txtScore = new Fitgy::TextEntity(getDisplay(), "Score: 0", mLabelFont,
                Fitgy::Color::white());
        txtScore->position.x = 10;
        txtScore->position.y = 10;

        imgDanger = new Fitgy::ImageEntity(getDisplay(), "gfx/danger.bmp");
        imgDanger->position.x = 10;
        imgDanger->position.y = getDisplay()->getHeight();
        imgDanger->position.y -= imgDanger->getHeight() + 20;

        mNextSpawnTime = getRandomSpawnTime();
        srand(time(NULL));

        addEntity(txtScore);
        addEntity(imgDanger);
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

}
