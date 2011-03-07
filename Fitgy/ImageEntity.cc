#include "ImageEntity.h"

namespace Fitgy {
    ImageEntity::ImageEntity(char *filename, short opacity)
        : Entity::Entity()
    {
        x = 0;
        y = 0;

        SDL_Surface* surfOriginal = NULL;

        if ((surfOriginal = SDL_LoadBMP(filename)) == NULL){
            throw "File couldn't be read.";
        }

        // Set alpha channel before converting the surface to the display
        // format, so that we can take advantage of hardware alpha blit
        // acceleration.
        SDL_SetAlpha(surfOriginal, SDL_SRCALPHA, opacity);

        // Convert the surface to the display format.
        entitySurface = SDL_DisplayFormat(surfOriginal);

        // Free resources taken by the old surface.
        SDL_FreeSurface(surfOriginal);

        width = entitySurface->w;
        height = entitySurface->h;
    }

    void
    ImageEntity::onRender(Entity* entity){
        drawToEntity(entity);
    }
}
