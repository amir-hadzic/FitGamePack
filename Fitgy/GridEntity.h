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

#ifndef FITGY_GRIDENTITY_H
#define FITGY_GRIDENTITY_H

#include <vector>
#include <map>
#include "LibSDL.h"
#include "Entity.h"
#include "ImageEntity.h"

namespace Fitgy {

    class GridEntity : public Entity {
    private:
        std::map<int, Entity*> mFields;
        int mFieldWidth;
        int mFieldHeight;
        int mDimension;
        SDL_Color mBackgroundColor;
        ImageEntity *mBackgroundImage;

    public:
        GridEntity(Entity* parent, int width, int height, int dimension);
        ~GridEntity();

        void onRender(Entity* entity);

        void addEntity(Entity* entity, int field);
        void removeEntity(int field);
        void setBackground(SDL_Color color);
        void setBackground(ImageEntity *imageEntity);
    };
}

#endif
