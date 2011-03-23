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
