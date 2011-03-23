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

#include "GridEntity.h"
#include "assert.h"

namespace Fitgy {
    GridEntity::GridEntity(Entity* parent, int width, int height, int dimension)
        : Entity(parent)
    {
        assert(dimension > 0);

        mDimension = dimension;
        mFieldWidth = width / dimension;
        mFieldHeight = height / dimension;

        mBackgroundColor.r = 0xaa;
        mBackgroundColor.g = 0xaa;
        mBackgroundColor.b = 0xaa;
        mBackgroundImage = NULL;

        mWidth = width;
        mHeight = height;

        entitySurface = SDL_CreateRGBSurface(
            SDL_HWSURFACE, width, height, 32, 0, 0, 0, 0
        );
    }

    GridEntity::~GridEntity()
    {
        // Destroy created entities.
        std::map<int, Entity*>::iterator it = mFields.begin();
        while(it != mFields.end()){
            delete (*it).second;
            (*it).second = NULL;
            ++it;
        }

        if (mBackgroundImage != NULL){
            delete mBackgroundImage;
        }
    }

    void
    GridEntity::onRender(Entity* entity){
        // TODO: Maybe the surface shouldn't be refilled each time
        // render() is called.
        SDL_FillRect(
            entitySurface,
            NULL,
            SDL_MapRGB(
                entitySurface->format,
                mBackgroundColor.r,
                mBackgroundColor.g,
                mBackgroundColor.b
            )
        );

        if (mBackgroundImage != NULL){
            mBackgroundImage->onRender(this);
        }

        std::map<int, Entity*>::iterator it;
        for(it = mFields.begin(); it != mFields.end(); it++){
            (*it).second->onRender(this);
        }

        drawToEntity(entity);
    }

    void
    GridEntity::addEntity(Entity* entity, int field){
        if (mFields.find(field) != mFields.end()){
            return;
        }

        entity->position.x = (field % mDimension) * mFieldWidth;
        entity->position.y = (field / mDimension) * mFieldHeight;
        mFields[field] = entity;
    }

    void
    GridEntity::removeEntity(int field){
        if (mFields.find(field) != mFields.end()){
            delete mFields[field];
            mFields.erase(field);
        }
    }

    void
    GridEntity::setBackground(SDL_Color color){
        mBackgroundColor = color;
    }

    void
    GridEntity::setBackground(ImageEntity* imageEntity){
        mBackgroundImage = imageEntity;
    }
}
