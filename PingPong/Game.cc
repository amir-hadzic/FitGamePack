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

        mBall = new Fitgy::ImageEntity(getDisplay(), "gfx/Ball.png",
                SDL_ALPHA_OPAQUE, true);

        mBall->position.x = 300;
        mBall->position.y = 300;
        mBall->direction = Fitgy::Vector::left;
        mBall->setSpeed(BALL_SPEED);

        addEntity(mBackgroundImage);
        addEntity(mPaddleLeft);
        addEntity(mPaddleRight);
        addEntity(mScoreLeft);
        addEntity(mScoreRight);
        addEntity(mBall);

        srand(time(NULL));
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

            // Rudimentary collision detection
            // First, we are going to check if the ball is out of the screen area.
            if (mBall->position.y >= 0 && mBall->position.x < 0){
                rightWins();
            } else if (mBall->position.y >= 0 &&
                    mBall->position.x > getDisplay()->getWidth())
            {
                leftWins();
            }

            // Floor or ceiling collision detection
            if (mBall->topRight().y > getDisplay()->getHeight()
                    || mBall->position.y <= 0)
            {
                    mBall->direction.y *= -1;

            }

            // Paddle collision detection
            if (mPaddleLeft->isWithinBounds(mBall->position) ||
                    mPaddleLeft->isWithinBounds(mBall->bottomLeft()))
            {
                mBall->direction.x = 1;
                mBall->direction.y = 1.0 / ((rand() % 2) + 1);
            } else if (mPaddleRight->isWithinBounds(mBall->topRight()) ||
                    mPaddleRight->isWithinBounds(mBall->bottomRight()))
            {
                mBall->direction.x = -1;
                mBall->direction.y = 1.0 / ((rand() % 2) + 1);
            }
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

    void
    Game::restart(){
        std::stringstream ss;

        mBall->position.x = 312;
        mBall->position.y = 232;
        mBall->direction = Fitgy::Vector::left;
        mBall->setSpeed(BALL_SPEED);

        ss << mLeftWins;
        mScoreLeft->setText(ss.str());

        ss.clear();
        ss.str(std::string());
        ss << mRightWins;
        mScoreRight->setText(ss.str());
    }

    void
    Game::leftWins(){
        mLeftWins++;
        restart();
    }

    void
    Game::rightWins(){
        mRightWins++;
        restart();
    }
}
