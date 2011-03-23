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

#ifndef FALLINGWORD_H
#define FALLINGWORD_H

#include "../Fitgy/Fitgy.h"
#include <string>

namespace Typer {

    class TyperWord : public Fitgy::Entity {
    private:
        Fitgy::TextEntity* mFinishedLetters;
        Fitgy::TextEntity* mUnfinishedLetters;
        unsigned short mFinishedCount;
        std::string mWord;
        TTF_Font* mFont;

    public:
        TyperWord(Fitgy::Entity* parent, std::string word, TTF_Font* font);
        ~TyperWord();

        void onRender(Fitgy::Entity* entity);
        void onLoop();
        bool onKeyDown(SDLKey sym, SDLMod mod, uint16_t unicode);
        bool isSolved();
    };
}

#endif