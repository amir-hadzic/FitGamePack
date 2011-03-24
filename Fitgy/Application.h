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

#ifndef FITGY_APPLICATION_H
#define FITGY_APPLICATION_H

#include "LibSDL.h"
#include "EventHandler.h"
#include "EventHub.h"
#include "Entity.h"
#include "Display.h"
#include <vector>
#include <algorithm>

namespace Fitgy {
    typedef std::vector<Entity*> EntityContainer;
    typedef EntityContainer::iterator EntityIterator;

    /**
     * This is the base class for a Fitgy Application. It handles the entities,
     * event broadcasting and everything else required to run a game.
     */
    class Application : public EventHandler {
    private:
        bool mRunning;

    protected:
        std::vector<Entity*> mEntities;
        Display* mDisplay;
        void startRender();

    public:
        /**
         * Constructor.
         */
        Application();

        /**
         * Destructor.
         */
        ~Application();

        /**
         * Runs the Application loop.
         *
         * @return 0 if the application executed succesfully and anything else
         * if it fails.
         */
        int execute();

        /**
         * Returns the display entity.
         *
         * @return the display entity associated with this application.
         */
        Display* getDisplay();

        /**
         * Adds an entity.
         *
         * @param entity is the target entity.
         */
        void addEntity(Entity* entity);

        /**
         * Removes the entity.
         *
         * @param entity is the target entity.
         */
        void removeEntity(Entity* entity);

        /**
         * Initializes the Application.
         *
         * Initializes the SDL libraries and creates an display entity.
         */
        virtual bool init();

        /**
         * This method is called on each application loop iteration and this
         * is where you should implement your game logic.
         */
        virtual void loop();

        /**
         * This method is called on each application loop iteration and this is
         * where you should implement your rendering code. By default this
         * method calls the onRender() method of each entity.
         */
        virtual void render();

        /**
         * This method is responsible for releasing any allocated resources such
         * as entities, fonts, etc.
         */
        virtual void cleanup();

        /**
         * onExit() implementation.
         * return true if the event is handled and shouldn't be broadcasted
         * further.
         */
        virtual bool onExit();
    };
}

#endif
