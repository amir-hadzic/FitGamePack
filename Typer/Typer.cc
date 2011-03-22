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

            // Find typed words and delete them.
            std::map<std::string, TyperWord*>::iterator it;
            it = mActiveWords.begin();
            while(it != mActiveWords.end()){
                if (it->second->isSolved()){
                    removeEntity(it->second);
                    it = mActiveWords.erase(it);
                } else {
                    ++it;
                }
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
        TyperWord* typerWord = new TyperWord(getDisplay(), word, mWordFont);

        int maxY = getDisplay()->getWidth() - typerWord->getWidth();
        typerWord->position.y = 0;
        typerWord->position.x = rand() % (maxY + 1);
        typerWord->direction = Fitgy::Vector::down;
        typerWord->setSpeed(200);

        mActiveWords[word] = typerWord;
        addEntity(typerWord);
    }

}
