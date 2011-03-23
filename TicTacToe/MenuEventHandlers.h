/**
*    This file is part of FitGamePack.
*
*    FitGamePack is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    FitGamePack is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with FitGamePack.  If not, see <http://www.gnu.org/licenses/>.
*
*    Author: Amir Hadzic <amir.hadzic@randomshouting.com>
*/

#ifndef MENU_EVENT_HANDLERS_H
#define MENU_EVENT_HANDLERS_H

#include "TicTacToe.h"

namespace TicTacToe {
    class MenuEventHandler : public Fitgy::EventHandler {
        bool onLMouseButtonUp(void* sender, SDL_Event*, Fitgy::Point){
            Fitgy::MenuItemEntity* menuItem = (Fitgy::MenuItemEntity*)sender;
            Game* game = Game::getInstance();

            if (menuItem->getIdentifier() == "quit"){
                game->onExit();
            } else if (menuItem->getIdentifier() == "restart") {
                game->restart();
            }

            return true;
        }
    };
}

#endif
