#include "Typer.h"

int main(int argc, char** argv){
    Typer::Game* game = Typer::Game::getInstance();
    return game->execute();
}
