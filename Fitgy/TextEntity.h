#ifndef FITGY_TEXTENTITY_H
#define FITGY_TEXTENTITY_H

#include "LibSDL.h"
#include "Entity.h"
#include <string>

namespace Fitgy {

    class TextEntity : public Entity {
    private:
        std::string mText;
        TTF_Font* mFont;
        SDL_Color mColor;

        void recreateSurface();
    public:
        TextEntity(
            Entity* parent,
            std::string text,
            TTF_Font* font,
            SDL_Color color
        );

        void onRender(Entity* entity);

        std::string getText();
        void setText(std::string text);
        SDL_Color getColor();
        void setColor(SDL_Color color);
    };
}

#endif
