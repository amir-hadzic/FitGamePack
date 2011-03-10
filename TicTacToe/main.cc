#include "TicTacToe.h"

int
main(void){
    TicTacToe::Game* game = TicTacToe::Game::getInstance();
    return game->execute();
}
