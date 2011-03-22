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
