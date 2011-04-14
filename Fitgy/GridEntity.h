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

/**
 * This entity can be used as a grid container for other entities.
 */
class GridEntity : public Entity {
private:
    std::map<int, Entity*> mFields;
    int mFieldWidth;
    int mFieldHeight;
    int mDimension;
    SDL_Color mBackgroundColor;
    ImageEntity *mBackgroundImage;

public:
    /**
     * Constructor.
     *
     * @param parent is the parent entity.
     * @param width is the width of the grid.
     * @param height is the height of the grid.
     * @param dimension is the number of rows and columns the grid is
     * supposed to have.
     */
    GridEntity(Entity* parent, int width, int height, int dimension);

    /**
     * Destructor.
     */
    ~GridEntity();

    /**
     * onRender() implementation.
     */
    void onRender(Entity* entity);

    /**
     * Adds an entity to the specifield field in the grid. Field numbers
     * start from zero up to dimension * dimension - 1.
     *
     * @param entity is the entity that is being added.
     * @param field is the position in the grid where the field will be
     * rendered.
     */
    void addEntity(Entity* entity, int field);

    /**
     * Removes an entity from the grid.
     *
     * @param field is the position at which the entity is located.
     */
    void removeEntity(int field);

    /**
     * Sets the background.
     *
     * @param color is the color that will be used as the background.
     */
    void setBackground(SDL_Color color);

    /**
     * Sets the background.
     *
     * @param imageEntity is the image entity that will be used as the
     * background.
     */
    void setBackground(ImageEntity *imageEntity);
};

}

#endif
