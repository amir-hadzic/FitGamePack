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
    mBackgroundImage = NULL;
    mPaddleLeft = NULL;
    mPaddleRight = NULL;
    mBall = NULL;
    mScoreLeft = NULL;
    mScoreRight = NULL;
    mPluckSound = NULL;
    mSwipeSound = NULL;
    mScoreFont = NULL;
    mLastSpeedChange = 0;
    mLeftWins = 0;
    mRightWins = 0;
}

Game::~Game(){
    delete mPluckSound;
    delete mSwipeSound;

    TTF_CloseFont(mScoreFont);
}

bool
Game::init()
{
    if (Application::init() == false) {
        return false;
    }

    getDisplay()->setTitle("Fitgy::Ping-Pong", "Ping-Pong");

    String base = executablePath();
    mScoreFont = TTF_OpenFont((base + SCORE_FONT).c_str(), 54);
    
    if (mScoreFont == NULL){
        throw Exception::FileNotFound(SCORE_FONT);
    }
    
    mSplashScreen = new SplashScreen(getDisplay(), base + "/gfx/Splash.png", 2000);
    mBackgroundImage = new ImageEntity(getDisplay(), base + "/gfx/Background.png");
    mPaddleLeft = new ImageEntity(getDisplay(), base + "/gfx/Paddle.png");
    mPaddleRight = new ImageEntity(getDisplay(), base + "/gfx/Paddle.png");
    mBall = new ImageEntity(getDisplay(), base + "/gfx/Ball.png",SDL_ALPHA_OPAQUE, true);
    mPluckSound = new Sound(base + "/sfx/pluck.ogg");
    mSwipeSound = new Sound(base + "/sfx/swipe.ogg", MIX_MAX_VOLUME / 2);

    mPaddleLeft->position.x = 10;
    mPaddleLeft->position.y = 190;
    mPaddleLeft->setSpeed(PADDLE_SPEED);

    mPaddleRight->position.x = 620;
    mPaddleRight->position.y = 190;
    mPaddleRight->setSpeed(PADDLE_SPEED);

    mScoreLeft = new TextEntity(getDisplay(), "0", mScoreFont, Color::fromRgb(63, 82, 43));
    mScoreLeft->position.x = 270;
    mScoreLeft->position.y = 10;

    mScoreRight = new TextEntity(getDisplay(), "0", mScoreFont, Color::fromRgb(63, 82, 43));
    mScoreRight->position.x = 340;
    mScoreRight->position.y = 10;

    mBall->position.x = 300;
    mBall->position.y = 300;
    mBall->direction = Vector::left;
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
    if (mSplashScreen == NULL){
        Application::loop();

        if (mLastSpeedChange == 0){
            mLastSpeedChange = SDL_GetTicks();
        }

        if (SDL_GetTicks() - mLastSpeedChange >= SPEED_CHANGE_TIME)
        {
            mBall->setSpeed( mBall->getSpeed() + (BALL_SPEED / 4) );
            mLastSpeedChange = SDL_GetTicks();
        }


        // Rudimentary collision detection
        // First, we are going to check if the ball is out of the screen area.
        if (mBall->position.y >= 0 && mBall->position.x < 0){
            mSwipeSound->play();
            rightWins();

            return;
        } else if (mBall->position.y >= 0 && mBall->position.x > getDisplay()->getWidth()){
            mSwipeSound->play();
            leftWins();

            return;
        }

        // Floor or ceiling collision detection
        if (mBall->bottomRight().y > getDisplay()->getHeight() || mBall->position.y <= 0)
        {
            mBall->direction.y *= -1;
            mPluckSound->play();
            return;
        }

        // Paddle collision detection
        // bounceAngle is the angle (in radians) for which the ball will be
        // rotated (plus the min. angle) when bounced back from the paddle.
        float bounceAngle = ( (float)rand() / (float)RAND_MAX ) * (1.0/2.0)*M_PI;

        if (mPaddleLeft->isWithinBounds(mBall->position) ||
                mPaddleLeft->isWithinBounds(mBall->bottomLeft()))
        {
            // Min. angle is -(1/4)PI
            // Max. angle is (1/4)PI
            mBall->direction.setAngle(( (1.0/4.0)*M_PI ) - bounceAngle);
            mPluckSound->play();

        } else if (mPaddleRight->isWithinBounds(mBall->topRight()) ||
                mPaddleRight->isWithinBounds(mBall->bottomRight()))
        {

            // Min. angle is (3/4)PI
            // Max. angle is (5/4)PI
            mBall->direction.setAngle(( (3.0/4.0)*M_PI ) + bounceAngle);
            mPluckSound->play();
        }
    } else {
        mSplashScreen->onLoop();
    }
}

bool
Game::onKeyDown(SDLKey sym, SDLMod mod, uint16_t unicode){
    switch(sym){
    case SDLK_w:
        mPaddleLeft->direction = Vector::up;
        break;
    case SDLK_UP:
        mPaddleRight->direction = Vector::up;
        break;
    case SDLK_s:
        mPaddleLeft->direction = Vector::down;
        break;
    case SDLK_DOWN:
        mPaddleRight->direction = Vector::down;
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
        mPaddleLeft->direction = Vector::zero;
        break;
    case SDLK_UP:
        mPaddleRight->direction = Vector::zero;
        break;
    case SDLK_s:
        mPaddleLeft->direction = Vector::zero;
        break;
    case SDLK_DOWN:
        mPaddleRight->direction = Vector::zero;
        break;
    default:
        break;
    }

    return true;
}

void
Game::restart(){
    mBall->position.x = 312;
    mBall->position.y = 232;
    mBall->direction = Vector::left;
    mBall->setSpeed(BALL_SPEED);

    mScoreLeft->setText(intToString(mLeftWins));
    mScoreRight->setText(intToString(mRightWins));
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
