#include "EventHub.h"

namespace Fitgy {
    std::vector<EventHub::EventListener> EventHub::mListeners;

    void
    EventHub::subscribe(EventHandler* handler){
        mListeners.push_back(EventListener(handler));
    }

    void
    EventHub::unsubscribe(EventHandler* handler){
        std::vector<EventListener>::iterator it;
        it = mListeners.begin();

        while(it != mListeners.end()){
            if ((*it).handler == handler){
                (*it).isActive = false;
                break;
            }
            ++it;
        }
    }

    void
    EventHub::broadcast(SDL_Event *event){
        std::vector<EventListener>::iterator it = mListeners.begin();

        while (it != mListeners.end()){
            if ((*it).isActive){
                (*it).handler->onEvent(NULL, event);
                ++it;
            } else {
                it = mListeners.erase(it);
            }
        }

    }
}
