#include "EventHandler.h"

namespace Fitgy {
    EventHandler::EventHandler(){

    }

    EventHandler::~EventHandler(){

    }

    bool
    EventHandler::onEvent(void* sender, SDL_Event* event){
        switch(event->type){
            case SDL_QUIT:
                return onExit();
                break;
            case SDL_MOUSEBUTTONDOWN: {
                Point point(event->button.x, event->button.y);
                return onMouseButtonDown(sender, event, point);
                break;
            }
            case SDL_MOUSEBUTTONUP: {
                Point point(event->button.x, event->button.y);
                return onMouseButtonUp(sender, event, point);
                break;
            }
            case SDL_MOUSEMOTION: {
                Point point(event->motion.x, event->motion.y);
                Point relPoint(event->motion.xrel, event->motion.yrel);
                return onMouseMove(sender, event, point, relPoint);
                break;
            }
        }

        return false;
    }

    bool
    EventHandler::onExit(){
        return false;
    }

    bool
    EventHandler::onMouseButtonDown(void* sender, SDL_Event* event, Point point){
        switch(event->button.button){
            case SDL_BUTTON_LEFT:
                return onLMouseButtonDown(sender, event, point);
                break;
            case SDL_BUTTON_RIGHT:
                return onRMouseButtonDown(sender, event, point);
                break;
            case SDL_BUTTON_MIDDLE:
                return onMMouseButtonDown(sender, event, point);
                break;
        }

        return false;
    }

    bool
    EventHandler::onLMouseButtonDown(void*, SDL_Event*, Point){
        return false;
    }

    bool
    EventHandler::onRMouseButtonDown(void*, SDL_Event*, Point){
        return false;
    }

    bool
    EventHandler::onMMouseButtonDown(void*, SDL_Event*, Point){
        return false;
    }

    bool
    EventHandler::onMouseButtonUp(void* sender, SDL_Event* event, Point point){
        switch(event->button.button){
            case SDL_BUTTON_LEFT:
                return onLMouseButtonUp(sender, event, point);
                break;
            case SDL_BUTTON_RIGHT:
                return onRMouseButtonUp(sender, event, point);
                break;
            case SDL_BUTTON_MIDDLE:
                return onMMouseButtonUp(sender, event, point);
                break;
        }

        return false;
    }

    bool
    EventHandler::onLMouseButtonUp(void*, SDL_Event*, Point){
        return false;
    }

    bool
    EventHandler::onRMouseButtonUp(void*, SDL_Event*, Point){
        return false;
    }

    bool
    EventHandler::onMMouseButtonUp(void*, SDL_Event*, Point){
        return false;
    }

    bool
    EventHandler::onMouseMove(void*, SDL_Event*, Point, Point){
        return false;
    }

    bool
    EventHandler::onMouseEnter(void*, SDL_Event*){
        return false;
    }

    bool
    EventHandler::onMouseLeave(void*, SDL_Event*){
        return false;
    }
}
