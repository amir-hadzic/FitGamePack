#include "TextEntity.h"

namespace Fitgy {

    TextEntity::TextEntity(
            Entity* parent, std::string text, TTF_Font* font, SDL_Color color
    )
        : Entity(parent)
    {
        mText = text;
        mColor = color;
        mFont = font;

        recreateSurface();
    }

    void
    TextEntity::recreateSurface(){
        if (entitySurface != NULL){
            SDL_FreeSurface(entitySurface);
            entitySurface = NULL;
        }

        entitySurface = TTF_RenderUTF8_Blended(mFont, mText.c_str(), mColor);
        mWidth = entitySurface->w;
        mHeight = entitySurface->h;
    }

    void
    TextEntity::onRender(Entity* entity){
        drawToEntity(entity);
    }

    void
    TextEntity::setText(std::string text){
        mText = text;

        recreateSurface();
    }

    std::string
    TextEntity::getText(){
        return mText;
    }

    void
    TextEntity::setColor(SDL_Color color){
        mColor = color;

        recreateSurface();
    }

    SDL_Color
    TextEntity::getColor(){
        return mColor;
    }
}
