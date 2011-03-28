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

#ifndef GRID_EVENT_HANDLERS_H
#define GRID_EVENT_HANDLERS_H

#include "TicTacToe.h"

namespace TicTacToe {
    class GridFieldEventHandler : public Fitgy::EventHandler {
        public:
            bool onMouseEnter(void* sender, SDL_Event*){
                Fitgy::FieldImageEntity* imgField = (Fitgy::FieldImageEntity*)sender;
                Game* game = Game::getInstance();

                if (game->fields[imgField->getField()] == Game::FieldType::Free){
                    imgField->setImage("gfx/B100_Hover.bmp");
                }

                return false;
            }

            bool onMouseLeave(void* sender, SDL_Event*){
                Fitgy::FieldImageEntity* imgField = (Fitgy::FieldImageEntity*)sender;
                Game* game = Game::getInstance();

                if (game->fields[imgField->getField()] == Game::FieldType::Free){
                    imgField->setImage("gfx/B100.bmp");
                }

                return false;
            }

            bool onLMouseButtonDown(void* sender, SDL_Event*, Fitgy::Point){
                Fitgy::FieldImageEntity* imgField = (Fitgy::FieldImageEntity*)sender;
                Game* game = Game::getInstance();

                if (game->fields[imgField->getField()] == Game::FieldType::Free){
                    if (game->xPlays){
                        imgField->setImage("gfx/X.bmp");
                        game->fields[imgField->getField()] = Game::FieldType::X;
                        game->soundDrawX->play();
                    } else {
                        imgField->setImage("gfx/O.bmp");
                        game->fields[imgField->getField()] = Game::FieldType::O;
                        game->soundDrawO->play();
                    }

                    game->nextPlayer();
                }

                return true;
            }
    };
}


#endif
