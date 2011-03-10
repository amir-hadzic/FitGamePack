#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "../Fitgy/Fitgy.h"
#include "assert.h"

namespace TicTacToe {

    class Game : public Fitgy::Application {
        private:
            Fitgy::SplashScreen *mSplashScreen;
            Game();
            Game(Game const&){};
            Game& operator=(Game const&){ return *this; };
            static Game* mInstance;

        public:
            enum FieldType {
                Free = 0,
                X = 1,
                O = 2
            };

            static Game* getInstance();
            Fitgy::GridEntity* gridEntity;
            Fitgy::TextEntity* textEntity;
            FieldType fields[9];
            bool xPlays;

            bool init();
            void render();
            void loop();

            void nextPlayer();
    };
}
#endif
