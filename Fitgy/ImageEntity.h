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
#include "Exception/FileNotFound.h"
#include "Util/String.h"

using namespace Fitgy::Util;

namespace Fitgy {
    
/**
 * An entity that represents an image.
 */
class ImageEntity : public Entity {
private:
    bool mImageWithAlpha;
public:
    /**
     * Constructor.
     *
     * @param parent is the parent entity.
     * @param filename is the path to the image file.
     * @param opacity is the initial opacity of the image. Default is
     * opaque.
     */
    ImageEntity(Entity* parent, String filename, short opacity = SDL_ALPHA_OPAQUE,
            bool imageWithAlpha = false);

    /**
     * onRender() implementation. The entity simply blits its surface to the
     * destination surface.
     */
    void onRender(Entity *entity);

    /**
     * Sets the image.
     *
     * @param fielname is the path to the image file.
     * @param opacity is the initial opacity of the image. Default is
     * opaque.
     */
    void setImage(String filename, short opacity = SDL_ALPHA_OPAQUE);

    /**
     * Changes the opacity of the image.
     *
     * @param opacity is the image opacity. Minimum value is
     * SDL_ALPHA_TRANSPARENT and maximum is SDL_ALPHA_OPAQUE.
     */
    void setOpacity(short opacity);
};

}

#endif
