#include "TicTacToe.h"

int
main(int argc, char** argv){
    TicTacToe::Game* game = TicTacToe::Game::getInstance();
    return game->execute();
}