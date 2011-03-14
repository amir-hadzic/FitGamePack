#ifndef FITGY_ENTITY_H
#define FITGY_ENTITY_H

#include "LibSDL.h"
#include <vector>
#include "Point.h"
#include "EventHandler.h"

namespace Fitgy {

    class Entity : public EventHandler {
        protected:
            void drawToEntity(Entity* entity);
            bool mMouseOver;
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

            void onMouseButtonDown(void* sender, SDL_Event* event, Point point);
            void onMouseButtonUp(void* sender, SDL_Event* event, Point point);
            void onMouseMove(void* sender, SDL_Event* event, Point point, Point relPoint);
            void onMouseEnter(void* sender, SDL_Event* event);
            void onMouseLeave(void* sender, SDL_Event* event);
    };
}

#endif
