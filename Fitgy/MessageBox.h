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
#ifndef FITGY_MESSAGEBOX_H
#define FITGY_MESSAGEBOX_H

#include "MessageBoxInt.h"

#ifdef _WIN32
#include "windows.h"
#else
#include <gtkmm/main.h>
#include <gtkmm/messagedialog.h>
#endif

namespace Fitgy {

class MessageBox {
private:
#ifdef _WIN32
    class MessageBoxWin : public MessageBoxInt {
    public:
        DialogResult show(std::string message, std::string title, Type type,
            Buttons buttons);
    };
    typedef MessageBoxWin _MessageBox;
#else
    class MessageBoxGtk : public MessageBoxInt {
    public:
        DialogResult show(std::string message, std::string title, Type type,
                    Buttons buttons);
    };
    typedef MessageBoxGtk _MessageBox;
#endif

public:
    static MessageBoxInt::DialogResult show(std::string message,
            std::string title, MessageBoxInt::Type type,
            MessageBoxInt::Buttons buttons);
};

}

#endif
