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

    class Application : public EventHandler {
    private:
        bool mRunning;

    protected:
        std::vector<Entity*> mEntities;
        Display* mDisplay;
        void startRender();

    public:
        Application();
        ~Application();
        int execute();
        Display* getDisplay();
        void addEntity(Entity* entity);
        void removeEntity(Entity* entity);

        virtual bool init();
        virtual void loop();
        virtual void render();
        virtual void cleanup();
        virtual bool onExit();
    };
}

#endif
