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
            int mWidth;
            int mHeight;
            EventHandler* mExternalEventHandler;

        public:
            Point position;
            SDL_Surface* entitySurface;
            Entity* parent;


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

            virtual void setHeight(int height);
            virtual void setWidth(int width);

            virtual int getHeight();
            virtual int getWidth();

            virtual void setEventHandler(EventHandler* handler);
            virtual EventHandler* getEventHandler();
    };
}

#endif
