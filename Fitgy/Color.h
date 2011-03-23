#ifndef FITGY_COlORS_H
#define FITGY_COlORS_H

#include "LibSDL.h"

namespace Fitgy {

    class Color {
    public:
        static SDL_Color fromRgb(
            unsigned int r,
            unsigned int g,
            unsigned int b
        );

        static SDL_Color red();
        static SDL_Color green();
        static SDL_Color blue();
        static SDL_Color white();
        static SDL_Color black();
        static SDL_Color yellow();

    };
}

#endif
