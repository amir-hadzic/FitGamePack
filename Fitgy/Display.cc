#include "Display.h"

namespace Fitgy {

    Display::Display(int width,int height)
        : Entity()
    {
        this->width = width;
        this->height = height;

        entitySurface = SDL_SetVideoMode(
            width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF
        );

        if (entitySurface == NULL){
            throw "Display couldn't be initialized.";
        }
    }
}
