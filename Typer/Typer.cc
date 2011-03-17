#include "Typer.h"

namespace Typer {
    Game* Game::mInstance = 0;

    Game* Game::getInstance(){
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

        mSplashScreen = new Fitgy::SplashScreen(
            mDisplay, "gfx/splash.bmp", 2000
        );

        TTF_Font* droidSans22px = TTF_OpenFont("fonts/DroidSans.ttf", 22);

        restart();
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

    void Game::loop(){
        if (mSplashScreen != NULL){
            mSplashScreen->onLoop();
    } else {
            Application::loop();
        }
    }

    void Game::restart(){

    }
}
