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
        case SDL_KEYDOWN:
            return onKeyDown(event->key.keysym.sym, event->key.keysym.mod,
                    event->key.keysym.unicode);
            break;
        case SDL_KEYUP:
            return onKeyUp(event->key.keysym.sym, event->key.keysym.mod,
                                event->key.keysym.unicode);
            break;
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

bool
EventHandler::onKeyDown(SDLKey, SDLMod, uint16_t){
    return false;
}

bool
EventHandler::onKeyUp(SDLKey, SDLMod, uint16_t){
    return false;
}

}
