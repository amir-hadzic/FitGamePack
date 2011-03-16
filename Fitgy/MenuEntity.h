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
            short mPadding;

        public:
            MenuEntity(Entity* parent, std::map<std::string, std::string> items, TTF_Font* font);
            ~MenuEntity();
            void redraw();
            void setBackgroundColor(SDL_Color color);
            void setBackgroundHoverColor(SDL_Color color);
            void setForegroundColor(SDL_Color color);
            void setPadding(short padding);
            void setEventHandler(EventHandler* handler);
            void onRender(Entity* entity);
            void onEvent(void* sender, SDL_Event* event);
    };
}

#endif
