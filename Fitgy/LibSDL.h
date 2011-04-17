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

#ifdef _WIN32
    #pragma comment(lib, "SDL.lib")
    #pragma comment(lib, "SDLmain.lib")
    #pragma comment(lib, "SDL_ttf.lib")
    #pragma comment(lib, "SDL_image.lib")
    #include <SDL.h>
    #include <SDL_ttf.h>
    #include <SDL_mixer.h>
    #include <SDL_image.h>
    #include <SDL_timer.h>
#else
    #include <SDL/SDL.h>
    #include <SDL/SDL_ttf.h>
    #include <SDL/SDL_mixer.h>
    #include <SDL/SDL_image.h>
    #include <SDL/SDL_timer.h>
#endif
