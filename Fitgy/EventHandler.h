#ifndef FITGY_EVENTHANDLER_H
#define FITGY_EVENTHANDLER_H

#include <SDL/SDL.h>
#include "Point.h"

namespace Fitgy {

    class EventHandler {
        public:
            EventHandler();
            virtual ~EventHandler();
            virtual void onEvent(SDL_Event* event);
            virtual void onExit();

            /* Event definitions */
            virtual void onMouseButtonDown(SDL_Event* event, Point point);
            virtual void onLMouseButtonDown(SDL_Event* event, Point point);
            virtual void onRMouseButtonDown(SDL_Event* event, Point point);
            virtual void onMMouseButtonDown(SDL_Event* event, Point point);

            virtual void onMouseButtonUp(SDL_Event* event, Point point);
            virtual void onLMouseButtonUp(SDL_Event* event, Point point);
            virtual void onRMouseButtonUp(SDL_Event* event, Point point);
            virtual void onMMouseButtonUp(SDL_Event* event, Point point);

    };
}

#endif
