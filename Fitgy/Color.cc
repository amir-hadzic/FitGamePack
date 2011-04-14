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

#include "Color.h"

namespace Fitgy {

SDL_Color
Color::fromRgb(unsigned int r, unsigned int g, unsigned int b){
    SDL_Color color;
    color.r = r;
    color.g = g;
    color.b = b;

    return color;
}

SDL_Color
Color::red(){
    SDL_Color color;
    color.r = 0xff;
    color.g = 0x00;
    color.b = 0x00;

    return color;
}

SDL_Color
Color::green(){
    SDL_Color color;
    color.r = 0x00;
    color.g = 0xff;
    color.b = 0x00;

    return color;
}

SDL_Color
Color::blue(){
    SDL_Color color;
    color.r = 0x00;
    color.g = 0x00;
    color.b = 0xff;

    return color;
}

SDL_Color
Color::white(){
    SDL_Color color;
    color.r = 0xff;
    color.g = 0xff;
    color.b = 0xff;

    return color;
}

SDL_Color
Color::black(){
    SDL_Color color;
    color.r = 0x00;
    color.g = 0x00;
    color.b = 0x00;

    return color;
}

SDL_Color
Color::yellow(){
    SDL_Color color;
    color.r = 0xff;
    color.g = 0xff;
    color.b = 0x00;

    return color;
}

}
