#include "TicTacToe.h"
#include "GridEventHandlers.h"

namespace TicTacToe {
    Game* Game::mInstance = 0;
    const int FIELD_FREE = 0;
    const int FIELD_X = 1;
    const int FIELD_O = 2;

    Game* Game::getInstance(){
        if (mInstance == NULL){
            mInstance = new Game();
        }

        return mInstance;
    }

    Game::Game(){
        xPlays = true;
        for (int i = 0; i < 9; fields[i++] = FieldType::Free);
    }

    bool
    Game::init()
    {
        if (Application::init() == false) {
            return false;
        }

        mSplashScreen = new Fitgy::SplashScreen(
            mDisplay, "gfx/TicTacToe_Splash.bmp", 2000
        );

        gridEntity = new Fitgy::GridEntity(mDisplay, 300, 300, 3);

        gridEntity->setBackground(new Fitgy::ImageEntity(gridEntity, "gfx/Sample.bmp"));
        gridEntity->position.setX(10);
        gridEntity->position.setY(10);

        GridFieldEventHandler* gridFieldEventHandler = new GridFieldEventHandler();
        for (int i = 0; i < 9; i++){
            Fitgy::ImageEntity* field = new Fitgy::FieldImageEntity(gridEntity, "gfx/B100.bmp", i);
            field->externalEventHandler = gridFieldEventHandler;
            gridEntity->addEntity(field, i);
        }

        gridEntity->externalEventHandler = new GridEventHandler();

        TTF_Font* textFont = TTF_OpenFont("fonts/DroidSansMono.ttf", 16);
        textEntity = new Fitgy::TextEntity(
            mDisplay, "Hello World!", textFont, {0xff, 0xff, 0xff, 0x00}
        );

        textEntity->position.setX(310);
        textEntity->position.setY(10);

        mEntities.push_back(gridEntity);
        mEntities.push_back(textEntity);

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

    void Game::nextPlayer(){
        xPlays = !xPlays;
    }
}
