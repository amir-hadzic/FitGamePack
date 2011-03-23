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
    };
}
#endif
