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
