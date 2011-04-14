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

#ifndef FITGY_DISPLAY_H
#define FITGY_DISPLAY_H

#include "Entity.h"
#include <string>

namespace Fitgy {

/**
 * This entity is used to represent the actual window/screen used for the
 * application.
 */
class Display: public Entity {
public:
    /**
     * Initializes the windows with the specified width and height.
     *
     * @param width is the width that will be used for the window.
     * @param height is the height that will be used for the window.
     */
    Display(int width, int height);

    /**
     * Sets the window title.
     *
     * @param windowTitle is the title that is shown at the top of the
     * window border.
     * @param iconTitle is the system title that might be used for the
     * taskbar. This actually depends on the operating system.
     */
    void setTitle(char* windowTitle, char* iconTitle);
};

}

#endif
