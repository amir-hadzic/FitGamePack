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

#include "Display.h"


namespace Fitgy {

Display::Display(int width,int height)
    : Entity()
{
    mWidth = width;
    mHeight = height;

#ifdef __linux
    setenv("SDL_VIDEO_CENTERED", "1", true);
#endif

    entitySurface = SDL_SetVideoMode(
        width, height, 32, SDL_HWSURFACE | SDL_DOUBLEBUF
    );

    if (entitySurface == NULL){
        // TODO: Throw an actual exception!
    	throw "Display couldn't be initialized.";
    }

#ifdef _WIN32
    SDL_SysWMinfo info;
	SDL_VERSION(&info.version);
	RECT rect;
	GetClientRect(GetDesktopWindow(),&rect);
	int monitorWidth = rect.right;
	int monitorHeight = rect.bottom;
	int x = monitorWidth / 2 - width / 2;
	int y = monitorHeight / 2 - height / 2;
	if (SDL_GetWMInfo(&info)){
		SetWindowPos(info.window, HWND_TOP, x, y, 0, 0, SWP_NOSIZE);
	}
#endif
}

void
Display::setTitle(String windowTitle, String iconTitle){
    SDL_WM_SetCaption(windowTitle.c_str(), iconTitle.c_str());
}
}
