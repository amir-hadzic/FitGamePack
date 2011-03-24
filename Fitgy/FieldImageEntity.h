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
#include "GridEntity.h"

namespace Fitgy {

    /**
     * An image entity that is enhanced for use with the grid entity.
     * @see ImageEntity
     */
    class FieldImageEntity : public ImageEntity {
    private:
        int mField;
    public:
        /**
         * Constructor that initializes the entity.
         *
         * @param parent is the parent entity. This should be but doesn't have
         * to be a GridEntity.
         * @param filename path to the image file.
         * @param field is the field position of this entity inside the parent
         * grid entity.
         * @param opacity is the opacity of the image. Default is opaque.
         */
        FieldImageEntity(GridEntity* parent, char* filename, int field, short opacity = SDL_ALPHA_OPAQUE);

        /**
         * Gets the field position.
         *
         * @return the field position of this entity inside the parent grid
         * entity.
         */
        int getField();
    };
}

#endif
