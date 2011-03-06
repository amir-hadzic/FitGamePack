#ifndef FITGY_ENTITY_H
#define FITGY_ENTITY_H

#include <SDL/SDL.h>
#include <vector>

namespace Fitgy {

    class Entity {
        protected:
            void drawToSurface(SDL_Surface* surface);

        public:
            float x;
            float y;
            int width;
            int height;
            SDL_Surface* entitySurface;

            Entity();
            virtual ~Entity();
            virtual void onLoop();
            virtual void onRender(Entity* entity);
            virtual void onCleanup();
    };
}

#endif
