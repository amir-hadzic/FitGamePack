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

#ifndef TYPER_H
#define TYPER_H

#include "../Fitgy/Fitgy.h"
#include "TyperWord.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>


namespace Typer {
    const std::string LABEL_FONT = "fonts/DroidSans.ttf";
    const std::string WORD_FONT = "fonts/DroidSansMono.ttf";

    class Game : public Fitgy::Application {
    private:
        Fitgy::SplashScreen *mSplashScreen;
        Game();
        Game(Game const&){};
        ~Game();
        Game& operator=(Game const&){ return *this; };
        static Game* mInstance;
        TTF_Font* mWordFont;
        TTF_Font* mLabelFont;
        unsigned int mNextSpawnTime;
        int mScore;

        std::vector<std::string> mWords;
        std::map<std::string, TyperWord*> mActiveWords;
        Fitgy::TextEntity* txtScore;
        Fitgy::ImageEntity* imgDanger;
        Fitgy::Sound* typingSound;

        void readWords(char* filename);
        std::string nextWord();
        void spawnWord();
        unsigned int getRandomSpawnTime();
        unsigned int getRandomSpeed();
        void updateScore();

    public:
        static Game* getInstance();

        bool init();
        void render();
        void loop();
        void restart();

        bool onKeyDown(SDLKey sym, SDLMod mod, uint16_t unicode);
    };
}
#endif
