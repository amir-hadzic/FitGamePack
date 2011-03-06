#ifndef FITGY_EVENTHANDLER_H
#define FITGY_EVENTHANDLER_H

#include <SDL/SDL.h>

namespace Fitgy {

    class EventHandler {
        public:
            EventHandler();
            virtual ~EventHandler();
            virtual void onEvent(SDL_Event* event);
            virtual void onExit();
    };
}

#endif
