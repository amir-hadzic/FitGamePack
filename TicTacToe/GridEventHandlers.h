#ifndef GRID_EVENT_HANDLERS_H
#define GRID_EVENT_HANDLERS_H

#include "TicTacToe.h"

namespace TicTacToe {
    class GridFieldEventHandler : public Fitgy::EventHandler {
        public:
            void onMouseEnter(void* sender, SDL_Event*){
                Fitgy::FieldImageEntity* imgField = (Fitgy::FieldImageEntity*)sender;
                Game* game = Game::getInstance();

                if (game->fields[imgField->getField()] == Game::FieldType::Free){
                        imgField->setImage("gfx/B100_Hover.bmp");
                }
            }

            void onMouseLeave(void* sender, SDL_Event*){
                Fitgy::FieldImageEntity* imgField = (Fitgy::FieldImageEntity*)sender;
                Game* game = Game::getInstance();

                if (game->fields[imgField->getField()] == Game::FieldType::Free){
                    imgField->setImage("gfx/B100.bmp");
                }
            }

            void onLMouseButtonDown(void* sender, SDL_Event*, Fitgy::Point){
                Fitgy::FieldImageEntity* imgField = (Fitgy::FieldImageEntity*)sender;
                Game* game = Game::getInstance();

                if (game->fields[imgField->getField()] == Game::FieldType::Free){
                    if (game->xPlays){
                        imgField->setImage("gfx/X.bmp");
                        game->fields[imgField->getField()] = Game::FieldType::X;
                    } else {
                        imgField->setImage("gfx/O.bmp");
                        game->fields[imgField->getField()] = Game::FieldType::O;
                    }

                    game->nextPlayer();
                }
            }
    };
}


#endif
