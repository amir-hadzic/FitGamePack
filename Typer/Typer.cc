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

    Game::Game(){
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

        mWordFont = TTF_OpenFont("fonts/DroidSans.ttf", 22);
        SDL_Color colorWhite;
        colorWhite.r = 0xff;
        colorWhite.g = 0xff;
        colorWhite.b = 0xff;

        Fitgy::TextEntity* txtTest = new Fitgy::TextEntity(
            getDisplay(),
            nextWord(),
            mWordFont,
            colorWhite
        );

        addEntity(txtTest);
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
            spawnWord();
        }

        Application::render();
    }

    void
    Game::loop(){
        if (mSplashScreen != NULL){
            mSplashScreen->onLoop();
    } else {
            Application::loop();
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
            srand(time(0));
            unsigned int randIndex = rand() % (mWords.size() + 1);
            std::string foundWord = mWords[randIndex];

            if (mActiveWords.find(foundWord) == mActiveWords.end()){
                word = foundWord;
            }
        }

        return word;
    }

    void
    Game::spawnWord(){
        srand(time(0));
        std::string word = nextWord();
        Fitgy::TextEntity* textEntity = new Fitgy::TextEntity(
            getDisplay(),
            word,
            mWordFont,
            Fitgy::Color::green()
        );

        int maxY = getDisplay()->getWidth() - textEntity->getWidth();
        textEntity->position.y = 0;
        textEntity->position.x = rand() % (maxY + 1);
        textEntity->direction = Fitgy::Vector::down;
        textEntity->setSpeed(200);

        mActiveWords[word] = textEntity;
        addEntity(textEntity);
    }

}
