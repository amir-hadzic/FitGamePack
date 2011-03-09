#ifndef FITGY_IMAGEENTITY_C
#define FITGY_IMAGEENTITY_C

#include <SDL/SDL.h>
#include "Entity.h"

namespace Fitgy {
    
    class ImageEntity : public Entity {
        public:
            ImageEntity(Entity* parent, char *filename, short opacity = SDL_ALPHA_OPAQUE);
            void onRender(Entity *entity);
    };
}

#endif
