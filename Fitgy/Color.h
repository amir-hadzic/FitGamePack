/**
*    This file is part of FitGamePack.
*
*    FitGamePack is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    FitGamePack is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with FitGamePack.  If not, see <http://www.gnu.org/licenses/>.
*
*    Author: Amir Hadzic <amir.hadzic@randomshouting.com>
*/

#ifndef FITGY_COlORS_H
#define FITGY_COlORS_H

#include "LibSDL.h"

namespace Fitgy {

    /**
     * This is a helper class that can be used to easily retrieve SDL_Color
     * structures.
     */
    class Color {
    public:
        /**
         * Generates a SDL_Color structure from the provided RGB values.
         *
         * @param r the red value of the color.
         * @param g the green value of the color.
         * @param b the blue value of the color.
         * @return the SDL_Color structure that represents the specified RGB
         * color.
         */
        static SDL_Color fromRgb(
            unsigned int r,
            unsigned int g,
            unsigned int b
        );

        /**
         * Returns the red color.
         *
         * @return the red color as a SDL_Color structure.
         */
        static SDL_Color red();

        /**
         * Returns the green color.
         *
         * @return the green color as a SDL_Color structure.
         */
        static SDL_Color green();

        /**
         * Returns the blue color.
         *
         * @return the blue color as a SDL_Color structure.
         */
        static SDL_Color blue();

        /**
         * Returns the white color.
         *
         * @return the white color as a SDL_Color structure.
         */
        static SDL_Color white();

        /**
         * Returns the black color.
         *
         * @return the black color as a SDL_Color structure.
         */
        static SDL_Color black();

        /**
         * Returns the yellow color.
         *
         * @return the yellow color as a SDL_Color structure.
         */
        static SDL_Color yellow();

    };
}

#endif
