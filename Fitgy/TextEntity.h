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

#ifndef FITGY_TEXTENTITY_H
#define FITGY_TEXTENTITY_H

#include "LibSDL.h"
#include "Entity.h"
#include "Util/String.h"

using namespace Fitgy::Util;

namespace Fitgy {

/**
 * An entity that can be used to write text to the screen.
 */
class TextEntity : public Entity {
private:
    String mText;
    TTF_Font* mFont;
    SDL_Color mColor;

    /**
     * Recreates the SDL_Surface for the entity. This is called when
     * the text, color or font is changed.
     */
    void recreateSurface();

public:
    /**
     * Constructor that takes the parent entity, text, font and color and
     * initializes the entity.
     *
     * @param parent is the parent entity.
     * @param text is the text that will be drawn.
     * @param font is the font that will be used for the text.
     * @param color is the color that will be used for the text.
     */
    TextEntity(Entity* parent, String text, TTF_Font* font, SDL_Color color);

    /**
     * onRender implementation for this entity. It simply blits the
     * generated surface to the specified entity. This method is supposed
     * to be called by the parent Entity or by the Application, depending
     * on who created it.
     *
     * @see Entity
     * @see Application
     * @param entity the entity to which to draw the text.
     */
    void onRender(Entity* entity);

    /**
     * Returns the text.
     *
     * @return The text that is used by this TextEntity as a std::string.
     */
    std::string getText();

    /**
     * Sets the text.
     *
     * @param text is the text that will be drawn.
     */
    void setText(String text);

    /**
     * Returns the color.
     *
     * @return The color that is used by this TextEntity as a SDL_Color.
     */
    SDL_Color getColor();

    /**
     * Sets the color.
     *
     * @param color is the color that will be used to draw the text.
     */
    void setColor(SDL_Color color);
};

}

#endif
