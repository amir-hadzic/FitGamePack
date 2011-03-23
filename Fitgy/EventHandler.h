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

#ifndef FITGY_EVENTHANDLER_H
#define FITGY_EVENTHANDLER_H

#include "LibSDL.h"
#include "Point.h"

namespace Fitgy {

    class EventHandler {
    public:
        EventHandler();
        virtual ~EventHandler();

        /* Event definitions */
        virtual bool onEvent(void* sender, SDL_Event* event);
        virtual bool onExit();

        virtual bool onMouseButtonDown(void* sender, SDL_Event* event, Point point);
        virtual bool onLMouseButtonDown(void* sender, SDL_Event* event, Point point);
        virtual bool onRMouseButtonDown(void* sender, SDL_Event* event, Point point);
        virtual bool onMMouseButtonDown(void* sender, SDL_Event* event, Point point);

        virtual bool onMouseButtonUp(void* sender, SDL_Event* event, Point point);
        virtual bool onLMouseButtonUp(void* sender, SDL_Event* event, Point point);
        virtual bool onRMouseButtonUp(void* sender, SDL_Event* event, Point point);
        virtual bool onMMouseButtonUp(void* sender, SDL_Event* event, Point point);

        virtual bool onMouseMove(void* sender, SDL_Event* event, Point point, Point relPoint);
        virtual bool onMouseEnter(void* sender, SDL_Event* event);
        virtual bool onMouseLeave(void* sender, SDL_Event* event);

        virtual bool onKeyDown(SDLKey sym, SDLMod mod, uint16_t unicode);
        virtual bool onKeyUp(SDLKey sym, SDLMod mod, uint16_t unicode);
    };
}

#endif
