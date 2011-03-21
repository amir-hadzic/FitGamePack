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
}
