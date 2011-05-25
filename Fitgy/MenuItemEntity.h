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

#ifndef FITGY_MENUITEMENTITY_H
#define FITGY_MENUITEMENTITY_H

#include "LibSDL.h"
#include "Entity.h"
#include "Color.h"
#include "TextEntity.h"
#include "Util/String.h"

using namespace Fitgy;

namespace Fitgy {

/**
 * This entity can be used as a standalone button or as a item in a menu.
 */
class MenuItemEntity : public Entity {
private:
    short mPadding;
    TextEntity* mTextEntity;
    String mIdentifier;
    SDL_Color mBackgroundColor;
    SDL_Color mBackgroundHoverColor;
    SDL_Color mCurrentBackgroundColor;
    SDL_Color mForegroundColor;
    TTF_Font *mFont;

    /**
     * Redraws the menu item. This is called when the graphical
     * representation of this entity is changed.
     */
    void redraw();

public:
    /**
     * Constructor.
     *
     * @param parent is the parent entity.
     * @param identifier is the identifier that can be used in an external
     * event handler to identify which menu item was clicked when used in a
     * menu.
     * @param text is the item text.
     * @param font is the font that will be used to draw the text.
     */
    MenuItemEntity(Entity* parent, String identifier, String text, TTF_Font* font);

    /**
     * Deletes the allocated resources such as the internal TextEntity.
     */
    ~MenuItemEntity();

    /**
     * Gets the background color.
     *
     * @return the background color of the menu item.
     */
    SDL_Color getBackgroundColor();

    /**
     * Sets the background color.
     *
     * @param color the color that will be used for the background.
     */
    void setBackgroundColor(SDL_Color color);

    /**
     * Gets the background hover color.
     *
     * @return the background hover color of the menu item.
     */
    SDL_Color getBackgroundHoverColor();

    /**
     * Sets the background hover color.
     *
     * @param color the color that will be used for the background while
     * the mouse is hovering over it.
     */
    void setBackgroundHoverColor(SDL_Color color);

    /**
     * Gets the font color.
     *
     * @return the font color as SDL_Color.
     */
    SDL_Color getForegroundColor();

    /**
     * Sets the font color.
     *
     * @param color the color that will be used to draw the text.
     */
    void setForegroundColor(SDL_Color color);

    /**
     * onRender() implementation for this entity.
     */
    void onRender(Entity* entity);

    /**
     * Implementation for setWidth(). Takes padding into consideration.
     *
     * @param width the width of the menu item (with padding).
     */
    void setWidth(int width);

    /**
     * Implementation for getWidth(). Takes padding into consideration.
     *
     * @return the width of this menu item.
     */
    int getWidth();

    /**
     * Implementation for setHeight(). Takes padding into consideration.
     *
     * @param height is the height of the menu item (width padding).
     */
    void setHeight(int height);

    /**
     * Implementation for getHeight(). Takes padding into consideration.
     *
     * @return the height of this menu item.
     */
    int getHeight();

    /**
     * Sets the padding.
     *
     * @param padding is the padding that will be used when drawing the text.
     */
    void setPadding(short padding);

    /**
     * Gets the padding.
     *
     * @return the padding of this menu item.
     */
    short getPadding();

    /**
     * Sets the text.
     *
     * @param the text that will be drawn on this menu item.
     */
    void setText(String text);

    /**
     * Gets the text.
     *
     * @return the text that is drawn on this menu item.
     */
    String getText();

    /**
     * Gets the identifier.
     *
     * @return the identifier that is set in the constructor.
     */
    String getIdentifier();

    /**
     * Implementation for onMouseEnter().
     *
     * Changes the background color to background hover color when the mouse
     * enters.
     */
    bool onMouseEnter(void* sender, SDL_Event* event);

    /**
     * Implementation for onMouseLeave().
     *
     * Changes the background hover color to background color when the mouse
     * leaves.
     */
    bool onMouseLeave(void* sender, SDL_Event* event);
};

}

#endif
