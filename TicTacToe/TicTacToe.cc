#include "TicTacToe.h"

bool
TicTacToe::init()
{
    if (Application::init() == false) {
        return false;
    }

    mSplashScreen = new Fitgy::SplashScreen(
        mDisplay, "gfx/TicTacToe_Splash.bmp", 2000
    );

    Fitgy::GridEntity* gridEntity = new Fitgy::GridEntity(mDisplay, 300, 300, 3);

    gridEntity->setBackground(new Fitgy::ImageEntity(gridEntity, "gfx/Sample.bmp"));
    gridEntity->position.setX(10);
    gridEntity->position.setY(10);

    gridEntity->addEntity(new Fitgy::ImageEntity(gridEntity, "gfx/B100.bmp"), 0);
    gridEntity->addEntity(new Fitgy::ImageEntity(gridEntity, "gfx/B100.bmp"), 1);
    gridEntity->addEntity(new Fitgy::ImageEntity(gridEntity, "gfx/X.bmp"), 2);
    gridEntity->addEntity(new Fitgy::ImageEntity(gridEntity, "gfx/B100.bmp"), 3);
    gridEntity->addEntity(new Fitgy::ImageEntity(gridEntity, "gfx/B100.bmp"), 4);
    gridEntity->addEntity(new Fitgy::ImageEntity(gridEntity, "gfx/B100.bmp"), 5);
    gridEntity->addEntity(new Fitgy::ImageEntity(gridEntity, "gfx/O.bmp"), 6);
    gridEntity->addEntity(new Fitgy::ImageEntity(gridEntity, "gfx/B100.bmp"), 7);
    gridEntity->addEntity(new Fitgy::ImageEntity(gridEntity, "gfx/B100.bmp"), 8);


    mEntities.push_back(gridEntity);

    return true;
}

void
TicTacToe::render(){
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

void TicTacToe::loop(){
    if (mSplashScreen != NULL){
        mSplashScreen->onLoop();
    } else {
        Application::loop();
    }
}


int
main(int argc, char** argv){
    TicTacToe game;

    return game.execute();
}
