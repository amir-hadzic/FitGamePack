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

#include "MenuItemEntity.h"

namespace Fitgy {

MenuItemEntity::MenuItemEntity(Entity* parent, std::string identifier,
        std::string text, TTF_Font *font)
: Entity(parent)
{
    mIdentifier = identifier;
    mFont = font;
    mForegroundColor = Color::black();
    mBackgroundColor = Color::red();
    mBackgroundHoverColor = Color::green();
    mTextEntity = new TextEntity(this, text, font, mForegroundColor);
    mPadding = 0;
    mWidth = mTextEntity->getWidth();
    mHeight = mTextEntity->getHeight();

    redraw();
    subscribe();
}

MenuItemEntity::~MenuItemEntity(){
    delete mTextEntity;
    mTextEntity = NULL;
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
        32, 0, 0, 0, 0
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

bool
MenuItemEntity::onMouseEnter(void* sender, SDL_Event* event){
    mCurrentBackgroundColor = mBackgroundHoverColor;
    redraw();

    return Entity::onMouseEnter(sender, event);
}

bool
MenuItemEntity::onMouseLeave(void* sender, SDL_Event* event){
    mCurrentBackgroundColor = mBackgroundColor;
    redraw();

    return Entity::onMouseLeave(sender, event);
}

void
MenuItemEntity::setPadding(short padding){
    mPadding = padding;
    mTextEntity->position.x = padding;
    mTextEntity->position.y = padding;
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
