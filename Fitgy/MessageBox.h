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
#include "Util/String.h"

#ifdef _WIN32
#include "windows.h"
#else
#include <gtkmm/main.h>
#include <gtkmm/messagedialog.h>
#endif

using namespace Fitgy::Util;

namespace Fitgy {

/**
 * MessageBox is used to display a dialog with a custom message, title and
 * buttons. It uses the windows API to show the dialog on Windows and Gtk
 * (gtkmm) on Linux.
 */
class MessageBox {
private:
#ifdef _WIN32
    class MessageBoxWin : public MessageBoxInt {
    public:
        DialogResult show(String message, String title, Type type, Buttons buttons);
    };
    typedef MessageBoxWin _MessageBox;
#else
    class MessageBoxGtk : public MessageBoxInt {
    public:
        DialogResult show(String message, String title, Type type, Buttons buttons);
    };
    typedef MessageBoxGtk _MessageBox;
#endif

public:
    /**
     * Display a message box.
     *
     * @param message is the message to show.
     * @param title is the title to use for the dialog window.
     * @param type is the type of the message.
     * @param buttons specifies which buttons will be shown on the dialog.
     *
     * @return the result code showing which button was clicked.
     */
    static MessageBoxInt::DialogResult show(String message, String title,
    		MessageBoxInt::Type type, MessageBoxInt::Buttons buttons);
};

}

#endif
