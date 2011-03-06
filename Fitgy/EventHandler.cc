#include "EventHandler.h"

namespace Fitgy {
    EventHandler::EventHandler(){

    }

    EventHandler::~EventHandler(){

    }

    void
    EventHandler::onEvent(SDL_Event *event){
        switch(event->type){
            case SDL_QUIT:
                onExit();
        }
    }

    void
    EventHandler::onExit(){

    }
}
