#ifndef FITGY_ENTITY_H
#define FITGY_ENTITY_H

#include <SDL/SDL.h>
#include <vector>
#include "Point.h"
#include "EventHandler.h"

namespace Fitgy {

    class Entity : public EventHandler {
        protected:
            void drawToEntity(Entity* entity);

        public:
            Point position;
            int width;
            int height;
            SDL_Surface* entitySurface;
            Entity* parent;
            EventHandler* externalEventHandler;

            Entity(Entity* parent = NULL);
            virtual ~Entity();
            virtual void onLoop();
            virtual void onRender(Entity* entity);
            virtual void onCleanup();

            Point getAbsPosition();
            bool isWithinBounds(Point point);

            void onMouseButtonDown(SDL_Event* event, Point point);
    };
}

#endif
