#include "ImageEntity.h"

namespace Fitgy {
    ImageEntity::ImageEntity(Entity* parent, char *filename, short opacity)
        : Entity::Entity(parent)
    {
        setImage(filename, opacity);
    }

    void
    ImageEntity::onRender(Entity* entity){
        drawToEntity(entity);
    }

    void
    ImageEntity::setImage(char* filename, short opacity){
        if (entitySurface != NULL){
            SDL_FreeSurface(entitySurface);
        }

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
}
