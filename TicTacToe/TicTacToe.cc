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

        try
        {
            mSplashScreen = new Fitgy::SplashScreen(mDisplay,
                    "gfx/TicTacToe_Splash.bmp", 2000);

            mFont = TTF_OpenFont(FONT.c_str(), 22);

            if (mFont == NULL){
                throw Fitgy::Exception::FileNotFound(FONT);
            }

            gridEntity = new Fitgy::GridEntity(mDisplay, 300, 300, 3);
            gridEntity->setBackground(new Fitgy::ImageEntity(gridEntity, "gfx/Sample.bmp"));
            gridEntity->position.x = 10;
            gridEntity->position.y = 10;

            txtWinsO = new Fitgy::TextEntity(mDisplay, "0", mFont, Fitgy::Color::white());
            txtWinsO->position.x = 429;
            txtWinsO->position.y = 260;

            txtWinsX = new Fitgy::TextEntity(mDisplay, "0", mFont, Fitgy::Color::white());
            txtWinsX->position.x = 549;
            txtWinsX->position.y = 260;

            txtPlaying = new Fitgy::TextEntity(mDisplay, "Currently playing:",
                    mFont, Fitgy::Color::white());

            txtPlaying->position.x = 388;
            txtPlaying->position.y = 29;

            imgPlayerO = new Fitgy::ImageEntity(mDisplay, "gfx/PlayerO.bmp", SDL_ALPHA_OPAQUE/2);
            imgPlayerO->position.x = 390;
            imgPlayerO->position.y = 80;

            imgPlayerX = new Fitgy::ImageEntity(mDisplay, "gfx/PlayerX.bmp", SDL_ALPHA_OPAQUE);
            imgPlayerX->position.x = 510;
            imgPlayerX->position.y = 80;

            mnuMain = new Fitgy::MenuEntity(mDisplay, mFont);
            mnuMain->setBackgroundColor(Fitgy::Color::fromRgb(0xaa, 0, 0));
            mnuMain->setBackgroundHoverColor(Fitgy::Color::red());
            mnuMain->setForegroundColor(Fitgy::Color::white());
            mnuMain->setPadding(5);
            mnuMain->position.x = 20;
            mnuMain->position.y = 346;
            mnuMain->addItem("restart", "Start new game");
            mnuMain->addItem("quit", "Quit");
            mnuMain->setEventHandler(new MenuEventHandler());

            soundDrawX = new Fitgy::Sound("sfx/draw-x.ogg");
            soundDrawO = new Fitgy::Sound("sfx/draw-o.ogg");

            addEntity(gridEntity);
            addEntity(txtWinsO);
            addEntity(txtWinsX);
            addEntity(txtPlaying);
            addEntity(imgPlayerO);
            addEntity(imgPlayerX);
            addEntity(mnuMain);

            restart();
        } catch (Fitgy::Exception::FileNotFound const &e){
            Fitgy::MessageBox::show("Resource not found: " + e.getFile(), "Error",
                                Fitgy::MessageBoxInt::MessageError, Fitgy::MessageBoxInt::ButtonOK);
            return false;
        }

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
