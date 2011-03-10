#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "../Fitgy/Fitgy.h"
#include "assert.h"

class TicTacToe : public Fitgy::Application {
    private:
        Fitgy::SplashScreen *mSplashScreen;

    public:
        Fitgy::GridEntity* gridEntity;
        Fitgy::TextEntity* textEntity;

        bool init();
        void render();
        void loop();
};

#endif
