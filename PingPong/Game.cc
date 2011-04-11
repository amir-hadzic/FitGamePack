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

#include "Game.h"

namespace PingPong {
    Game* Game::mInstance = NULL;

    Game* Game::getInstance(){
        if (mInstance == NULL){
            mInstance = new Game();
        }

        return mInstance;
    }

    Game::Game(){
        mSplashScreen = NULL;
    }

    bool
    Game::init()
    {
        if (Application::init() == false) {
            return false;
        }

        getDisplay()->setTitle("Fitgy::Ping-Pong", "Ping-Pong");

        mScoreFont = TTF_OpenFont("fonts/DroidSans.ttf", 54);

        mSplashScreen = new Fitgy::SplashScreen(getDisplay(), "gfx/Splash.png", 2000);
        mBackgroundImage = new Fitgy::ImageEntity(getDisplay(), "gfx/Background.png");

        mPaddleLeft = new Fitgy::ImageEntity(getDisplay(), "gfx/Paddle.png");
        mPaddleLeft->position.x = 10;
        mPaddleLeft->position.y = 190;
        mPaddleLeft->setSpeed(PADDLE_SPEED);

        mPaddleRight = new Fitgy::ImageEntity(getDisplay(), "gfx/Paddle.png");
        mPaddleRight->position.x = 620;
        mPaddleRight->position.y = 190;
        mPaddleRight->setSpeed(PADDLE_SPEED);

        mScoreLeft = new Fitgy::TextEntity(getDisplay(), "0",
                mScoreFont, Fitgy::Color::fromRgb(63, 82, 43));
        mScoreLeft->position.x = 270;
        mScoreLeft->position.y = 10;

        mScoreRight = new Fitgy::TextEntity(getDisplay(), "0",
                        mScoreFont, Fitgy::Color::fromRgb(63, 82, 43));
        mScoreRight->position.x = 340;
        mScoreRight->position.y = 10;

        addEntity(mBackgroundImage);
        addEntity(mPaddleLeft);
        addEntity(mPaddleRight);
        addEntity(mScoreLeft);
        addEntity(mScoreRight);
        return true;
    }

    void
    Game::render(){
        if (mSplashScreen != NULL && !mSplashScreen->isFinished()){
            mSplashScreen->onRender(getDisplay());
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
        }
    }

    bool
    Game::onKeyDown(SDLKey sym, SDLMod mod, uint16_t unicode){
        switch(sym){
        case SDLK_w:
            mPaddleLeft->direction = Fitgy::Vector::up;
            break;
        case SDLK_UP:
            mPaddleRight->direction = Fitgy::Vector::up;
            break;
        case SDLK_s:
            mPaddleLeft->direction = Fitgy::Vector::down;
            break;
        case SDLK_DOWN:
            mPaddleRight->direction = Fitgy::Vector::down;
            break;
        default:
            break;
        }

        return true;
    }

    bool
    Game::onKeyUp(SDLKey sym, SDLMod mod, uint16_t unicode){
        switch(sym){
        case SDLK_w:
            mPaddleLeft->direction = Fitgy::Vector::zero;
            break;
        case SDLK_UP:
            mPaddleRight->direction = Fitgy::Vector::zero;
            break;
        case SDLK_s:
            mPaddleLeft->direction = Fitgy::Vector::zero;
            break;
        case SDLK_DOWN:
            mPaddleRight->direction = Fitgy::Vector::zero;
            break;
        default:
            break;
        }

        return true;
    }
}
