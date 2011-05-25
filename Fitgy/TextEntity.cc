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

#include "TextEntity.h"

namespace Fitgy {

TextEntity::TextEntity(Entity* parent, String text, TTF_Font* font,
        SDL_Color color)
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
TextEntity::setText(String text){
    mText = text;

    recreateSurface();
}

String
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
