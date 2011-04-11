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

#include "ImageEntity.h"

namespace Fitgy {
    ImageEntity::ImageEntity(Entity* parent, char *filename, short opacity)
        : Entity(parent)
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

        if ((surfOriginal = IMG_Load(filename)) == NULL){
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

        mWidth = entitySurface->w;
        mHeight = entitySurface->h;
    }
    
    void
    ImageEntity::setOpacity(short opacity){
        SDL_SetAlpha(entitySurface, SDL_SRCALPHA, opacity);
    }
}
