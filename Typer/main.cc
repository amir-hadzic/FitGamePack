#include "Typer.h"

int main(void){
    Typer::Game* game = Typer::Game::getInstance();
    return game->execute();
}
