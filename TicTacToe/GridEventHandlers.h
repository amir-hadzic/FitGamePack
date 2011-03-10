#ifndef GRID_EVENT_HANDLERS_H
#define GRID_EVENT_HANDLERS_H

#include "TicTacToe.h"

namespace TicTacToe {
    class GridFieldEventHandler : public Fitgy::EventHandler {
        public:
            void onMouseEnter(void* sender, SDL_Event*){
                Fitgy::FieldImageEntity* field = (Fitgy::FieldImageEntity*)sender;
                Game* game = Game::getInstance();

                if (game->fields[field->getField()] == Game::FieldType::Free){
                    field->setImage("gfx/B100_Hover.bmp");
                }
            }

            void onMouseLeave(void* sender, SDL_Event*){
                Fitgy::FieldImageEntity* field = (Fitgy::FieldImageEntity*)sender;
                Game* game = Game::getInstance();

                if (game->fields[field->getField()] == Game::FieldType::Free){
                    field->setImage("gfx/B100.bmp");
                }
            }

            void onLMouseButtonDown(void* sender, SDL_Event*, Fitgy::Point){
                Fitgy::FieldImageEntity* field = (Fitgy::FieldImageEntity*)sender;
                Game* game = Game::getInstance();

                if (game->fields[field->getField()] == Game::FieldType::Free){
                    if (game->xPlays){
                        field->setImage("gfx/X.bmp");
                        game->fields[field->getField()] = Game::FieldType::X;
                    } else {
                        field->setImage("gfx/O.bmp");
                        game->fields[field->getField()] = Game::FieldType::O;
                    }

                    game->nextPlayer();
                }
            }
    };

    class GridEventHandler : public Fitgy::EventHandler {
        public:
            void onLMouseButtonDown(void*, SDL_Event*, Fitgy::Point point){
                Game* game = Game::getInstance();
                game->textEntity->setText("Left button down: " + (std::string)point);
            }

            void onRMouseButtonDown(void*, SDL_Event*, Fitgy::Point point){
                Game* game = Game::getInstance();
                game->textEntity->setText("Right button down: " + (std::string)point);
            }

            void onMMouseButtonDown(void*, SDL_Event*, Fitgy::Point point){
                Game* game = Game::getInstance();
                game->textEntity->setText("Middle button down: " + (std::string)point);
            }

            void onLMouseButtonUp(void*, SDL_Event*, Fitgy::Point point){
                Game* game = Game::getInstance();
                game->textEntity->setText("Left button up: " + (std::string)point);
            }

            void onRMouseButtonUp(void*, SDL_Event*, Fitgy::Point point){
                Game* game = Game::getInstance();
                game->textEntity->setText("Right button up: " + (std::string)point);
            }

            void onMMouseButtonUp(void*, SDL_Event*, Fitgy::Point point){
                Game* game = Game::getInstance();
                game->textEntity->setText("Middle button up: " + (std::string)point);
            }

            void onMouseEnter(void*, SDL_Event*){
                Game* game = Game::getInstance();
                game->textEntity->setText("Mouse entered the grid entity.");
            }

            void onMouseLeave(void*, SDL_Event*){
                Game* game = Game::getInstance();
                game->textEntity->setText("Mouse left the grid entity.");
            }
    };
}


#endif
