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

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "../Fitgy/Fitgy.h"
#include <map>
#include "assert.h"

#define IS_ROW_HIT(f1, f2, f3) fields[f1] == fields[f2]\
&& fields[f2] == fields[f3] && fields[f3] != FieldType::Free

using namespace Fitgy;
using namespace Fitgy::Util;

namespace TicTacToe {

const String FONT = "/fonts/DroidSans.ttf";
const String SPLASH_IMAGE = "/gfx/Splash.png";
const String BLANK_FIELD_IMAGE = "/gfx/FieldBlank.png";
const String HOVER_FIELD_IMAGE = "/gfx/FieldBlank_Hover.png";
const String X_FIELD_IMAGE = "/gfx/FieldX.png";
const String O_FIELD_IMAGE = "/gfx/FieldO.png";
const String X_IMAGE = "/gfx/PlayerX.png";
const String O_IMAGE = "/gfx/PlayerO.png";
const String X_DRAW_SOUND = "/sfx/draw-x.ogg";
const String O_DRAW_SOUND = "/sfx/draw-o.ogg";

class Game : public Application {
private:
    Game();
    Game(Game const&){};
    Game& operator=(Game const&){ return *this; };
    void checkForWin();
	void announceWin();
    static Game* mInstance;
    SplashScreen *mSplashScreen;
    TTF_Font* mFont;
    int mWinsX;
    int mWinsO;
public:
    enum FieldType {
        Free = 0,
        X = 1,
        O = 2
    };

    static Game* getInstance();
    bool init();
    void render();
    void loop();
    void restart();
    void nextPlayer();
    void cleanup();

    GridPanel* gridEntity;
    TextEntity* txtWinsX;
    TextEntity* txtWinsO;
    TextEntity* txtPlaying;
    ImageEntity* imgPlayerX;
    ImageEntity* imgPlayerO;
    MenuEntity* mnuMain;
    Sound* soundDrawX;
    Sound* soundDrawO;
    FieldType fields[9];
    bool xPlays;
    bool gameOver;
};

}
#endif
