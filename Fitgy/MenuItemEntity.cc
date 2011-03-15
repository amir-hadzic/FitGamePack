#include "MenuItemEntity.h"

namespace Fitgy {
    MenuItemEntity::MenuItemEntity(
        Entity* parent,
        std::string identifier,
        std::string text,
        TTF_Font *font
    ) : Entity(parent)
    {
        mIdentifier = identifier;
        mFont = font;
        mForegroundColor.r = 0xff;
        mForegroundColor.g = 0xff;
        mForegroundColor.b = 0xff;
        mTextEntity = new TextEntity(this, text, font, mForegroundColor);
        mPadding = 0;
        mWidth = mTextEntity->getWidth();
        mHeight = mTextEntity->getHeight();

        redraw();
    }

    void
    MenuItemEntity::redraw(){
        if (entitySurface != NULL){
            SDL_FreeSurface(entitySurface);
            entitySurface = NULL;
        }

        entitySurface = SDL_CreateRGBSurface(
            SDL_HWSURFACE | SDL_SRCALPHA,
            getWidth(),
            getHeight(),
            parent->entitySurface->format->BitsPerPixel,
            parent->entitySurface->format->Rmask,
            parent->entitySurface->format->Gmask,
            parent->entitySurface->format->Bmask,
            parent->entitySurface->format->Amask
        );

        SDL_FillRect(
            entitySurface,
            NULL,
            SDL_MapRGB(
                entitySurface->format,
                mCurrentBackgroundColor.r,
                mCurrentBackgroundColor.g,
                mCurrentBackgroundColor.b
            )
        );

        mTextEntity->onRender(this);
    }

    void
    MenuItemEntity::onRender(Entity* entity){
        drawToEntity(entity);
    }

    void
    MenuItemEntity::onMouseEnter(void* sender, SDL_Event* event){
        mCurrentBackgroundColor = mBackgroundColor;
        redraw();
    }

    void
    MenuItemEntity::onMouseLeave(void* sender, SDL_Event* event){
        mCurrentBackgroundColor = mBackgroundHoverColor;
        redraw();
    }

    void
    MenuItemEntity::setPadding(short padding){
        mPadding = padding;
        mTextEntity->position.setX(padding);
        mTextEntity->position.setY(padding);
        redraw();
    }

    short
    MenuItemEntity::getPadding(){
        // Both X and Y values are the same, return X.
        return mPadding;
    }

    void
    MenuItemEntity::setText(std::string text){
        mTextEntity->setText(text);
    }

    std::string
    MenuItemEntity::getText(){
        return mTextEntity->getText();
    }

    std::string
    MenuItemEntity::getIdentifier(){
        return mIdentifier;
    }

    SDL_Color
    MenuItemEntity::getBackgroundColor(){
        return mBackgroundColor;
    }

    void
    MenuItemEntity::setBackgroundColor(SDL_Color color){
        mBackgroundColor = color;
        mCurrentBackgroundColor = color;
        redraw();
    }

    SDL_Color
    MenuItemEntity::getBackgroundHoverColor(){
        return mBackgroundHoverColor;
        redraw();
    }

    void
    MenuItemEntity::setBackgroundHoverColor(SDL_Color color){
        mBackgroundHoverColor = color;
        redraw();
    }

    SDL_Color
    MenuItemEntity::getForegroundColor(){
        return mForegroundColor;
    }

    void
    MenuItemEntity::setForegroundColor(SDL_Color color){
        mForegroundColor = color;
        mTextEntity->setColor(color);
    }

    void
    MenuItemEntity::setWidth(int width){
        mWidth = width - (mPadding * 2);
        redraw();
    }

    int
    MenuItemEntity::getWidth(){
        return mWidth + (mPadding * 2);
    }

    void
    MenuItemEntity::setHeight(int height)
    {
        mHeight = height - (mPadding * 2);
        redraw();
    }

    int
    MenuItemEntity::getHeight(){
        return mHeight + (mPadding * 2);
    }
}
