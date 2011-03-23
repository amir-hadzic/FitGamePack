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
#include <string>
#include "assert.h"
#include <sstream>

#define IS_ROW_HIT(f1, f2, f3) fields[f1] == fields[f2]\
&& fields[f2] == fields[f3] && fields[f3] != FieldType::Free

namespace TicTacToe {

    class Game : public Fitgy::Application {
    private:
        Fitgy::SplashScreen *mSplashScreen;
        Game();
        Game(Game const&){};
        Game& operator=(Game const&){ return *this; };
        static Game* mInstance;
        int winsX;
        int winsO;
        void checkForWin();
        void announceWin();
    public:
        enum FieldType {
            Free = 0,
            X = 1,
            O = 2
        };

        static Game* getInstance();
        Fitgy::GridEntity* gridEntity;

        Fitgy::TextEntity* txtWinsX;
        Fitgy::TextEntity* txtWinsO;
        Fitgy::TextEntity* txtPlaying;

        Fitgy::ImageEntity* imgPlayerX;
        Fitgy::ImageEntity* imgPlayerO;

        Fitgy::MenuEntity* mnuMain;

        FieldType fields[9];
        bool xPlays;
        bool gameOver;
        bool init();
        void render();
        void loop();
        void restart();

        void nextPlayer();
    };
}
#endif
