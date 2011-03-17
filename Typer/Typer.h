#ifndef TYPER_H
#define TYPER_H

#include "../Fitgy/Fitgy.h"

namespace Typer {

    class Game : public Fitgy::Application {
        private:
            Fitgy::SplashScreen *mSplashScreen;
            Game();
            Game(Game const&){};
            Game& operator=(Game const&){ return *this; };
            static Game* mInstance;

        public:
            static Game* getInstance();

            bool init();
            void render();
            void loop();
            void restart();
    };
}
#endif
