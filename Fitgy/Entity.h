#ifndef FITGY_ENTITY_H
#define FITGY_ENTITY_H

#include <SDL/SDL.h>
#include <vector>
#include "Point.h"
#include "EventHandler.h"

#define EVENT_CALLBACK(e) void (*e)(void* sender, SDL_Event* event)
#define FIRE_EVENT(e) if(e != NULL) { e((void*)this, event); }

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

            Entity(Entity* parent = NULL);
            virtual ~Entity();
            virtual void onLoop();
            virtual void onRender(Entity* entity);
            virtual void onCleanup();

            Point getAbsPosition();
            bool isWithinBounds(Point point);

            void onMouseButtonDown(SDL_Event* event, Point point);

            EVENT_CALLBACK(onMouseButtonDownCallback);
    };
}

#endif
