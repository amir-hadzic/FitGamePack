#ifndef FITGY_EVENTHANDLER_H
#define FITGY_EVENTHANDLER_H

#include "LibSDL.h"
#include "Point.h"

namespace Fitgy {

    class EventHandler {
        public:
            EventHandler();
            virtual ~EventHandler();
            virtual void onEvent(void* sender, SDL_Event* event);
            virtual void onExit();

            /* Event definitions */
            virtual void onMouseButtonDown(void* sender, SDL_Event* event, Point point);
            virtual void onLMouseButtonDown(void* sender, SDL_Event* event, Point point);
            virtual void onRMouseButtonDown(void* sender, SDL_Event* event, Point point);
            virtual void onMMouseButtonDown(void* sender, SDL_Event* event, Point point);

            virtual void onMouseButtonUp(void* sender, SDL_Event* event, Point point);
            virtual void onLMouseButtonUp(void* sender, SDL_Event* event, Point point);
            virtual void onRMouseButtonUp(void* sender, SDL_Event* event, Point point);
            virtual void onMMouseButtonUp(void* sender, SDL_Event* event, Point point);

            virtual void onMouseMove(void* sender, SDL_Event* event, Point point, Point relPoint);
            virtual void onMouseEnter(void* sender, SDL_Event* event);
            virtual void onMouseLeave(void* sender, SDL_Event* event);
    };
}

#endif
