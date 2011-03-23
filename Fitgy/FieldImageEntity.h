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

#ifndef FITGY_FIELDIMAGEENTITY_H
#define FITGY_FIELDIMAGEENTITY_H

#include "ImageEntity.h"

namespace Fitgy {

    class FieldImageEntity : public ImageEntity {
    private:
        int mField;
    public:
        FieldImageEntity(Entity* parent, char* filename, int field, short opacity = SDL_ALPHA_OPAQUE);
        int getField();
        bool onMouseMove(void* sender, SDL_Event* event, Point point, Point relPoint);
        bool onMouseEnter(void* sender, SDL_Event* event);
    };
}

#endif
