#include "TicTacToe.h"
#include "GridEventHandlers.h"
#include "MenuEventHandlers.h"

namespace TicTacToe {
    Game* Game::mInstance = NULL;
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

        mDisplay->setTitle("Fitgy::TicTacToe", "TicTacToe");

        mSplashScreen = new Fitgy::SplashScreen(
            mDisplay, "gfx/TicTacToe_Splash.bmp", 2000
        );

        TTF_Font* droidSansMono22px = TTF_OpenFont("fonts/DroidSans.ttf", 22);

        gridEntity = new Fitgy::GridEntity(mDisplay, 300, 300, 3);
        gridEntity->setBackground(new Fitgy::ImageEntity(gridEntity, "gfx/Sample.bmp"));
        gridEntity->position.x = 10;
        gridEntity->position.y = 10;

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

        SDL_Color colorDarkRed;
        colorDarkRed.r = 0xaa;
        colorDarkRed.g = 0x00;
        colorDarkRed.b = 0x00;

        txtWinsO = new Fitgy::TextEntity(
            mDisplay,
            "0",
            droidSansMono22px,
            colorWhite
        );
        txtWinsO->position.x = 429;
        txtWinsO->position.y = 260;

        txtWinsX = new Fitgy::TextEntity(
            mDisplay,
            "0",
            droidSansMono22px,
            colorWhite
        );
        txtWinsX->position.x = 549;
        txtWinsX->position.y = 260;

        txtPlaying = new Fitgy::TextEntity(
            mDisplay,
            "Currently playing:",
            droidSansMono22px,
            colorWhite
        );

        txtPlaying->position.x = 388;
        txtPlaying->position.y = 29;
        txtPlaying->setColor(colorWhite);

        imgPlayerO = new Fitgy::ImageEntity(mDisplay, "gfx/PlayerO.bmp", SDL_ALPHA_OPAQUE/2);
        imgPlayerO->position.x = 390;
        imgPlayerO->position.y = 80;

        imgPlayerX = new Fitgy::ImageEntity(mDisplay, "gfx/PlayerX.bmp", SDL_ALPHA_OPAQUE);
        imgPlayerX->position.x = 510;
        imgPlayerX->position.y = 80;

        mnuMain = new Fitgy::MenuEntity(mDisplay, droidSansMono22px);
        mnuMain->setBackgroundColor(colorDarkRed);
        mnuMain->setBackgroundHoverColor(colorRed);
        mnuMain->setForegroundColor(colorWhite);
        mnuMain->setPadding(5);
        mnuMain->position.x = 20;
        mnuMain->position.y = 346;
        mnuMain->addItem("restart", "Start new game");
        mnuMain->addItem("quit", "Quit");
        mnuMain->setEventHandler(new MenuEventHandler());

        addEntity(gridEntity);
        addEntity(txtWinsO);
        addEntity(txtWinsX);
        addEntity(txtPlaying);
        addEntity(imgPlayerO);
        addEntity(imgPlayerX);
        addEntity(mnuMain);

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
            Fitgy::FieldImageEntity* field = new Fitgy::FieldImageEntity(gridEntity, "gfx/B100.bmp", i);
            field->setEventHandler(gridFieldEventHandler);
            gridEntity->removeEntity(i);
            gridEntity->addEntity(field, i);
        }

    	gameOver = false;
    }
}
