#ifndef TYPER_H
#define TYPER_H

#include "../Fitgy/Fitgy.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <string>

namespace Typer {

    class Game : public Fitgy::Application {
    private:
        Fitgy::SplashScreen *mSplashScreen;
        Game();
        Game(Game const&){};
        Game& operator=(Game const&){ return *this; };
        static Game* mInstance;
        int mPoints;
        TTF_Font* mWordFont;
        std::vector<std::string> mWords;
        std::map<std::string, Fitgy::TextEntity*> mActiveWords;
        void readWords(char* filename);
        std::string nextWord();
        void spawnWord();

    public:
        static Game* getInstance();

        bool init();
        void render();
        void loop();
        void restart();
    };
}
#endif
