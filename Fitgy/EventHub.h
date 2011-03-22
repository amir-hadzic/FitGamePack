#ifndef FITGY_EVENTHUB_H
#define FITGY_EVENTHUB_H

#include "LibSDL.h"
#include "EventHandler.h"
#include <vector>
#include <algorithm>

namespace Fitgy {

    class EventHub {
    private:
        struct EventListener
        {
            public:
                EventListener(EventHandler* handler){
                    isActive = true;
                    this->handler = handler;
                }
                EventHandler* handler;
                bool isActive;
        };
        static std::vector<EventListener> mListeners;

    public:

        static void subscribe(EventHandler* handler);
        static void unsubscribe(EventHandler* handler);
        static void broadcast(SDL_Event* event);
    };
}

#endif
