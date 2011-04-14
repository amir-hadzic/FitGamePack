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

/**
 * EventHub is used to distribute events across all active Entities or any
 * other EventHandler instances.
 */
class EventHub {
private:
    /**
     * EventListener is a structure that holds the handle of the EventHandler
     * instance and a state variable that signals the EventHub if it should
     * delete this EventHandler from it's list of subscribed EventHandlers.
     */
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

    /**
     * Subscribes the specified EventHandler to receive events.
     *
     * @param handler is the EventHandler that needs to receive events.
     */
    static void subscribe(EventHandler* handler);

    /**
     * Deletes the specified EventHandler from the list of subscribed
     * EventHandlers. Once unsubscribed the EventHandler will no longer
     * receive events.
     *
     * @param handler is the EventHandler that no longer want to receive
     * events.
     */
    static void unsubscribe(EventHandler* handler);

    /**
     * Sends the specified event to all subscribed EventHandlers. This
     * method is usually called by the Application.
     *
     * @param event is the event that needs to be broadcasted.
     */
    static void broadcast(SDL_Event* event);
};

}

#endif
