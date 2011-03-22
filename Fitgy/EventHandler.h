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
    };
}

#endif
