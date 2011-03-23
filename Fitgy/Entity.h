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

#ifndef FITGY_ENTITY_H
#define FITGY_ENTITY_H

#include "LibSDL.h"
#include <vector>
#include "Point.h"
#include "Vector.h"
#include "EventHandler.h"
#include "EventHub.h"

namespace Fitgy {

    class Entity : public EventHandler {
    protected:
        void drawToEntity(Entity* entity);
        bool mMouseOver;
        int mWidth;
        int mHeight;
        float mSpeed;
        unsigned int mLastLoopTime;
        EventHandler* mExternalEventHandler;
        Entity(Entity const&){};
        Entity& operator=(Entity const&){ return *this; };
    public:
        Point position;
        SDL_Surface* entitySurface;
        Vector direction;
        Entity* parent;


        Entity(Entity* parent = NULL);
        virtual ~Entity();
        virtual void onLoop();
        virtual void onRender(Entity* entity);
        virtual void onCleanup();

        Point getAbsPosition();
        bool isWithinBounds(Point point);

        bool onMouseButtonDown(void* sender, SDL_Event* event, Point point);
        bool onMouseButtonUp(void* sender, SDL_Event* event, Point point);
        bool onMouseMove(void* sender, SDL_Event* event, Point point, Point relPoint);
        bool onMouseEnter(void* sender, SDL_Event* event);
        bool onMouseLeave(void* sender, SDL_Event* event);

        virtual void setHeight(int height);
        virtual void setWidth(int width);

        virtual int getHeight();
        virtual int getWidth();

        virtual void setSpeed(float speed);
        virtual float getSpeed();

        virtual void setEventHandler(EventHandler* handler);
        virtual EventHandler* getEventHandler();
    };
}

#endif
