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

#include "EventHub.h"

namespace Fitgy {

int EventHub::numListeners = 0;
bool EventHub::mListLocked = false;
std::vector<EventHub::EventListener> EventHub::mListeners;

void
EventHub::subscribe(EventHandler* handler){
    mListeners.push_back(EventListener(handler));
    numListeners++;
}

void
EventHub::unsubscribe(EventHandler* handler){
    std::vector<EventListener>::iterator it;
    it = mListeners.begin();
    while(it != mListeners.end()){
        if (it->handler == handler){
            if (true){
                it->isActive = false;
            } else {
                mListeners.erase(it);
            }
            numListeners--;
            break;
        }
        ++it;
    }
}

void
EventHub::broadcast(SDL_Event* event){
    std::vector<EventListener>::iterator it = mListeners.begin();

    mListLocked = true;
    while (it != mListeners.end()){
        if (it->isActive){
            it->handler->dummy();
            bool handled = it->handler->onEvent(NULL, event);

            if (handled){
                break;
            }

            ++it;
        } else {
            it = mListeners.erase(it);
        }
    }
    mListLocked = false;

}

}
