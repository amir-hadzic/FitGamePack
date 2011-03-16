#include "Display.h"

namespace Fitgy {

    Display::Display(int width,int height)
        : Entity()
    {
        mWidth = width;
        mHeight = height;

        entitySurface = SDL_SetVideoMode(
            width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF
        );

        if (entitySurface == NULL){
            throw "Display couldn't be initialized.";
        }
    }

    void
    Display::setTitle(char* windowTitle, char* iconTitle){
        SDL_WM_SetCaption(windowTitle, iconTitle);
    }
}
