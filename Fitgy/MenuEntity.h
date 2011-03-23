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

    class MenuEntity : public Entity {
    private:
        std::vector<MenuItemEntity*> mMenuItems;
        SDL_Color mBackgroundColor;
        SDL_Color mBackgroundHoverColor;
        SDL_Color mForegroundColor;
        TTF_Font* mFont;
        EventHandler* mItemEventHandler;
        short mPadding;

    public:
        MenuEntity(Entity* parent, TTF_Font* font);
        ~MenuEntity();
        void redraw();
        void addItem(std::string identifier, std::string text);
        void setBackgroundColor(SDL_Color color);
        void setBackgroundHoverColor(SDL_Color color);
        void setForegroundColor(SDL_Color color);
        void setPadding(short padding);
        void setEventHandler(EventHandler* handler);
        void onRender(Entity* entity);
    };
}

#endif
