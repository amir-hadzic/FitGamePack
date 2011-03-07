#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "../Fitgy/Fitgy.h"

class TicTacToe : public Fitgy::Application {
    private:
        Fitgy::SplashScreen *mSplashScreen;

    public:
        bool init();
        void render();
        void loop();
};

#endif
