#include "EventHandler.h"

namespace Fitgy {
    EventHandler::EventHandler(){

    }

    EventHandler::~EventHandler(){

    }

    void
    EventHandler::onEvent(void* sender, SDL_Event* event){
        switch(event->type){
            case SDL_QUIT:
                onExit();
                break;
            case SDL_MOUSEBUTTONDOWN: {
                Point point(event->button.x, event->button.y);
                onMouseButtonDown(sender, event, point);
                break;
            }
            case SDL_MOUSEBUTTONUP: {
                Point point(event->button.x, event->button.y);
                onMouseButtonUp(sender, event, point);
                break;
            }
            case SDL_MOUSEMOTION: {
                Point point(event->motion.x, event->motion.y);
                Point relPoint(event->motion.xrel, event->motion.yrel);
                onMouseMove(sender, event, point, relPoint);
                break;
            }
        }
    }

    void
    EventHandler::onExit(){

    }

    void
    EventHandler::onMouseButtonDown(void* sender, SDL_Event* event, Point point){
        switch(event->button.button){
            case SDL_BUTTON_LEFT:
                onLMouseButtonDown(sender, event, point);
                break;
            case SDL_BUTTON_RIGHT:
                onRMouseButtonDown(sender, event, point);
                break;
            case SDL_BUTTON_MIDDLE:
                onMMouseButtonDown(sender, event, point);
                break;
        }
    }

    void
    EventHandler::onLMouseButtonDown(void*, SDL_Event*, Point){

    }

    void
    EventHandler::onRMouseButtonDown(void*, SDL_Event*, Point){

    }

    void
    EventHandler::onMMouseButtonDown(void*, SDL_Event*, Point){

    }

    void
    EventHandler::onMouseButtonUp(void* sender, SDL_Event* event, Point point){
        switch(event->button.button){
            case SDL_BUTTON_LEFT:
                onLMouseButtonUp(sender, event, point);
                break;
            case SDL_BUTTON_RIGHT:
                onRMouseButtonUp(sender, event, point);
                break;
            case SDL_BUTTON_MIDDLE:
                onMMouseButtonUp(sender, event, point);
                break;
        }
    }

    void
    EventHandler::onLMouseButtonUp(void*, SDL_Event*, Point){

    }

    void
    EventHandler::onRMouseButtonUp(void*, SDL_Event*, Point){

    }

    void
    EventHandler::onMMouseButtonUp(void*, SDL_Event*, Point){

    }

    void
    EventHandler::onMouseMove(void*, SDL_Event*, Point, Point){

    }

    void
    EventHandler::onMouseEnter(void*, SDL_Event*){

    }

    void
    EventHandler::onMouseLeave(void*, SDL_Event*){

    }
}
