#ifndef FITGY_IMAGEENTITY_C
#define FITGY_IMAGEENTITY_C

#include "LibSDL.h"
#include "Entity.h"

namespace Fitgy {
    
    class ImageEntity : public Entity {
    public:
        ImageEntity(Entity* parent, char *filename, short opacity = SDL_ALPHA_OPAQUE);
        void onRender(Entity *entity);
        void setImage(char* filename, short opacity = SDL_ALPHA_OPAQUE);
        void setOpacity(short opacity);
    };
}

#endif
