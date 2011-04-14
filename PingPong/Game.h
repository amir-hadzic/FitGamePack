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

#ifndef PINGPONG_GAME_H
#define PINGPONG_GAME_H

#include "../Fitgy/Fitgy.h"
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>

#define _USE_MATH_DEFINES
#include <cmath>

namespace PingPong {

const std::string SCORE_FONT = "fonts/DroidSans.ttf";
const float PADDLE_SPEED = 400;
const float BALL_SPEED = 220;
const int SPEED_CHANGE_TIME = 3500;

class Game : public Fitgy::Application {
private:
    Game();
    ~Game();

    Game(Game const&){};
    Game& operator=(Game const&){ return *this; };

    static Game* mInstance;
    Fitgy::SplashScreen* mSplashScreen;
    Fitgy::ImageEntity* mBackgroundImage;
    Fitgy::ImageEntity* mPaddleLeft;
    Fitgy::ImageEntity* mPaddleRight;
    Fitgy::ImageEntity* mBall;
    Fitgy::TextEntity* mScoreLeft;
    Fitgy::TextEntity* mScoreRight;
    Fitgy::Sound* mPluckSound;
    Fitgy::Sound* mSwipeSound;
    TTF_Font* mScoreFont;

    unsigned int mLastSpeedChange;
    int mLeftWins;
    int mRightWins;

    void leftWins();
    void rightWins();
    void restart();

public:
    static Game* getInstance();
    bool init();
    void loop();
    void render();
    bool onKeyDown(SDLKey sym, SDLMod mod, uint16_t unicode);
    bool onKeyUp(SDLKey sym, SDLMod mod, uint16_t unicode);
};

}


#endif
