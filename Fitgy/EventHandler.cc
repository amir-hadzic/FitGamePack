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
            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonDown(
                    event,
                    Point(event->button.x, event->button.y)
                );
                break;
        }
    }

    void
    EventHandler::onExit(){

    }

    void
    EventHandler::onMouseButtonDown(SDL_Event*, Point){

    }
}
