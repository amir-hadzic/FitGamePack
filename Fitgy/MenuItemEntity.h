#ifndef FITGY_MENUITEMENTITY_H
#define FITGY_MENUITEMENTITY_H

#include "LibSDL.h"
#include "Entity.h"
#include "TextEntity.h"
#include <string>

namespace Fitgy {

    class MenuItemEntity : public Entity {
    private:
        short mPadding;
        TextEntity* mTextEntity;
        std::string mIdentifier;
        SDL_Color mBackgroundColor;
        SDL_Color mBackgroundHoverColor;
        SDL_Color mCurrentBackgroundColor;
        SDL_Color mForegroundColor;
        TTF_Font *mFont;

    public:
        MenuItemEntity(
            Entity* parent,
            std::string identifier,
            std::string text,
            TTF_Font* font
        );
        ~MenuItemEntity();
        void redraw();
        void setPadding(short padding);
        short getPadding();
        void setText(std::string text);
        std::string getText();
        std::string getIdentifier();
        SDL_Color getBackgroundColor();
        void setBackgroundColor(SDL_Color color);
        SDL_Color getBackgroundHoverColor();
        void setBackgroundHoverColor(SDL_Color color);
        SDL_Color getForegroundColor();
        void setForegroundColor(SDL_Color color);

        void onRender(Entity* entity);

        void setWidth(int width);
        int getWidth();
        void setHeight(int height);
        int getHeight();

        bool onMouseEnter(void* sender, SDL_Event* event);
        bool onMouseLeave(void* sender, SDL_Event* event);
    };
}

#endif
