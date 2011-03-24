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

#ifndef FITGY_MENUENTITY_H
#define FITGY_MENUENTITY_H

#include <vector>
#include <map>
#include "assert.h"
#include "LibSDL.h"
#include "EventHandler.h"
#include "MenuItemEntity.h"

namespace Fitgy {

    /**
     * MenuEntity is used for displaying multiple MenuItemEntities sorted
     * vertically.
     */
    class MenuEntity : public Entity {
    private:
        std::vector<MenuItemEntity*> mMenuItems;
        SDL_Color mBackgroundColor;
        SDL_Color mBackgroundHoverColor;
        SDL_Color mForegroundColor;
        TTF_Font* mFont;
        EventHandler* mItemEventHandler;
        short mPadding;

        void redraw();
    public:
        /**
         * Initializes the menu.
         *
         * Note that you will have to call addItem() with appropriate parameters
         * in order to add menu items.
         *
         * @param parent is the parent entity.
         * @param font is the font that will be used by every menu item.
         */
        MenuEntity(Entity* parent, TTF_Font* font);

        /**
         * Destroys the allocated resources such as the internal
         * MenuItemEntities.
         */
        ~MenuEntity();

        /**
         * Adds another menu item.
         *
         * @param identifier the identifier for the menu item.
         * @param text is the text for the menu item.
         */
        void addItem(std::string identifier, std::string text);

        /**
         * Sets the background color.
         *
         * @param color is the background color that every menu item will use.
         */
        void setBackgroundColor(SDL_Color color);

        /**
         * Sets the background hover color.
         *
         * @param color is the background hover color that every menu item
         * will use.
         */
        void setBackgroundHoverColor(SDL_Color color);

        /**
         * Sets the foreground color.
         *
         * @param color is the text color of the menu items.
         */
        void setForegroundColor(SDL_Color color);

        /**
         * Sets the padding.
         *
         * @param padding is the padding for the menu items.
         */
        void setPadding(short padding);

        /**
         * Sets the event handler.
         *
         * This event handler will be applied to each menu item.
         *
         * @param handler is the external EventHandler instance.
         */
        void setEventHandler(EventHandler* handler);

        /**
         * Implementation for the onRender() entity method.
         */
        void onRender(Entity* entity);
    };
}

#endif
