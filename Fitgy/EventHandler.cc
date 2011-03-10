#include "EventHandler.h"

namespace Fitgy {
    EventHandler::EventHandler(){

    }

    EventHandler::~EventHandler(){

    }

    void
    EventHandler::onEvent(SDL_Event* event){
        switch(event->type){
            case SDL_QUIT:
                onExit();
                break;
            case SDL_MOUSEBUTTONDOWN: {
                Point point(event->button.x, event->button.y);
                onMouseButtonDown(event, point);

                switch(event->button.button){
                    case SDL_BUTTON_LEFT:
                        onLMouseButtonDown(event, point);
                        break;
                    case SDL_BUTTON_RIGHT:
                        onRMouseButtonDown(event, point);
                        break;
                    case SDL_BUTTON_MIDDLE:
                        onMMouseButtonDown(event, point);
                        break;
                }

                break;
            }
            case SDL_MOUSEBUTTONUP: {
                Point point(event->button.x, event->button.y);
                onMouseButtonUp(event, point);

                switch(event->button.button){
                    case SDL_BUTTON_LEFT:
                        onLMouseButtonUp(event, point);
                        break;
                    case SDL_BUTTON_RIGHT:
                        onRMouseButtonUp(event, point);
                        break;
                    case SDL_BUTTON_MIDDLE:
                        onMMouseButtonUp(event, point);
                        break;
                }

                break;
            }
        }
    }

    void
    EventHandler::onExit(){

    }

    void
    EventHandler::onMouseButtonDown(SDL_Event*, Point){

    }

    void
    EventHandler::onLMouseButtonDown(SDL_Event*, Point){

    }

    void
    EventHandler::onRMouseButtonDown(SDL_Event*, Point){

    }

    void
    EventHandler::onMMouseButtonDown(SDL_Event*, Point){

    }

    void
    EventHandler::onMouseButtonUp(SDL_Event*, Point){

    }

    void
    EventHandler::onLMouseButtonUp(SDL_Event*, Point){

    }

    void
    EventHandler::onRMouseButtonUp(SDL_Event*, Point){

    }

    void
    EventHandler::onMMouseButtonUp(SDL_Event*, Point){

    }
}
