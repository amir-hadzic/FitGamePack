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
        gridEntity = NULL;

        txtPlaying = NULL;
        txtWinsO = NULL;
        txtWinsX = NULL;
        imgPlayerX = NULL;
        imgPlayerO = NULL;
        winsX = 0;
        winsO = 0;
        gameOver = false;
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

        TTF_Font* droidSansMono22px = TTF_OpenFont("fonts/DroidSans.ttf", 22);

        gridEntity = new Fitgy::GridEntity(mDisplay, 300, 300, 3);
        gridEntity->setBackground(new Fitgy::ImageEntity(gridEntity, "gfx/Sample.bmp"));
        gridEntity->position.setX(10);
        gridEntity->position.setY(10);

        SDL_Color colorWhite;
        colorWhite.r = 0xff;
        colorWhite.g = 0xff;
        colorWhite.b = 0xff;

        SDL_Color colorBlack;
        colorBlack.r = 0x00;
        colorBlack.g = 0x00;
        colorBlack.b = 0x00;

        SDL_Color colorRed;
        colorRed.r = 0xff;
        colorRed.g = 0x00;
        colorRed.b = 0x00;

        txtWinsO = new Fitgy::TextEntity(
            mDisplay,
            "0",
            droidSansMono22px,
            colorWhite
        );
        txtWinsO->position.setX(429);
        txtWinsO->position.setY(260);

        txtWinsX = new Fitgy::TextEntity(
            mDisplay,
            "0",
            droidSansMono22px,
            colorWhite
        );
        txtWinsX->position.setX(549);
        txtWinsX->position.setY(260);

        txtPlaying = new Fitgy::TextEntity(
            mDisplay,
            "Currently playing:",
            droidSansMono22px,
            colorWhite
        );

        txtPlaying->position.setX(388);
        txtPlaying->position.setY(29);
        txtPlaying->setColor(colorWhite);

        imgPlayerO = new Fitgy::ImageEntity(mDisplay, "gfx/PlayerO.bmp", SDL_ALPHA_OPAQUE/2);
        imgPlayerO->position.setX(390);
        imgPlayerO->position.setY(80);

        imgPlayerX = new Fitgy::ImageEntity(mDisplay, "gfx/PlayerX.bmp", SDL_ALPHA_OPAQUE);
        imgPlayerX->position.setX(510);
        imgPlayerX->position.setY(80);

        Fitgy::MenuItemEntity* menuItem = new Fitgy::MenuItemEntity(
            mDisplay,
            "menuItem",
            "Test item",
            droidSansMono22px
        );

        menuItem->setBackgroundColor(colorRed);
        menuItem->setBackgroundHoverColor(colorBlack);
        menuItem->setForegroundColor(colorWhite);
        menuItem->setPadding(5);
        menuItem->position.setX(400);
        menuItem->position.setY(400);

        mEntities.push_back(gridEntity);
        mEntities.push_back(txtWinsO);
        mEntities.push_back(txtWinsX);
        mEntities.push_back(txtPlaying);
        mEntities.push_back(imgPlayerO);
        mEntities.push_back(imgPlayerX);
        mEntities.push_back(menuItem);

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

    void Game::nextPlayer(){
        checkForWin();
        xPlays = !xPlays;
        
        if (xPlays){
            imgPlayerX->setOpacity(SDL_ALPHA_OPAQUE);
            imgPlayerO->setOpacity(SDL_ALPHA_OPAQUE/2);
        } else {
            imgPlayerX->setOpacity(SDL_ALPHA_OPAQUE/2);
            imgPlayerO->setOpacity(SDL_ALPHA_OPAQUE);
        }
    }

    void Game::checkForWin(){
        bool horizontalHit1 = IS_ROW_HIT(0, 1, 2);
        bool horizontalHit2 = IS_ROW_HIT(3, 4, 5);
        bool horizontalHit3 = IS_ROW_HIT(6, 7, 8);

        bool verticalHit1 = IS_ROW_HIT(0, 3, 6);
        bool verticalHit2 = IS_ROW_HIT(1, 4, 7);
        bool verticalHit3 = IS_ROW_HIT(2, 5, 8);

        bool diagonalHit1 = IS_ROW_HIT(6, 4, 2);
        bool diagonalHit2 = IS_ROW_HIT(0, 4, 8);

        if (
            horizontalHit1 || horizontalHit2 || horizontalHit3 ||
            verticalHit1 || verticalHit2 || verticalHit3 ||
            diagonalHit1 || diagonalHit2
        ){
            announceWin();
        }
    }

    void Game::announceWin(){
        std::stringstream ss;
        if (xPlays){
            ss << ++winsX;
            txtWinsX->setText(ss.str());
        } else {
            ss << ++winsO;
            txtWinsO->setText(ss.str());
        }

        restart();
    }

    void Game::restart(){
    	for (int i = 0; i < 9; fields[i++] = FieldType::Free);

    	GridFieldEventHandler* gridFieldEventHandler = new GridFieldEventHandler();
		for (int i = 0; i < 9; i++){
			Fitgy::ImageEntity* field = new Fitgy::FieldImageEntity(gridEntity, "gfx/B100.bmp", i);
			field->externalEventHandler = gridFieldEventHandler;
			gridEntity->removeEntity(i);
			gridEntity->addEntity(field, i);
		}

    	gameOver = false;
    }
}
