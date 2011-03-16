#ifndef MENU_EVENT_HANDLERS_H
#define MENU_EVENT_HANDLERS_H

#include "TicTacToe.h"

namespace TicTacToe {
    class MenuEventHandler : public Fitgy::EventHandler {
        void onLMouseButtonUp(void* sender, SDL_Event*, Fitgy::Point){
            Fitgy::MenuItemEntity* menuItem = (Fitgy::MenuItemEntity*)sender;
            Game* game = Game::getInstance();

            if (menuItem->getIdentifier() == "quit"){
                game->onExit();
            } else if (menuItem->getIdentifier() == "restart") {
                game->restart();
            }
        }
    };
}

#endif
