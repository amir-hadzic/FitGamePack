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
#ifndef _WIN32

#include "MessageBox.h"

namespace Fitgy {

/**
 * Windows implementation of the message box dialog using Gtk (gtkmm).
 */
MessageBox::MessageBoxGtk::DialogResult
MessageBox::MessageBoxGtk::show(std::string message, std::string title,
        Type type, Buttons buttons)
{
    Gtk::Main kit(0, NULL);

    int messageType = 0;
    switch(type){
    case MessageInfo:
        messageType = Gtk::MESSAGE_INFO;
        break;
    case MessageWarning:
        messageType = Gtk::MESSAGE_WARNING;
        break;
    case MessageQuestion:
        messageType = Gtk::MESSAGE_QUESTION;
        break;
    case MessageError:
        messageType = Gtk::MESSAGE_ERROR;
        break;
    default:
        messageType = Gtk::MESSAGE_INFO;
    }

    int messageButtons = 0;
    switch(buttons){
    case ButtonOK:
        messageButtons = Gtk::BUTTONS_OK;
        break;
    case ButtonOKCancel:
        messageButtons = Gtk::BUTTONS_OK_CANCEL;
        break;
    case ButtonYesNo:
        messageButtons = Gtk::BUTTONS_YES_NO;
        break;
    default:
        messageButtons = Gtk::BUTTONS_OK;
    }

    Gtk::MessageDialog msgBox(message, false, (Gtk::MessageType)messageType,
            (Gtk::ButtonsType)messageButtons, true);

    msgBox.set_title(title);
    int result = msgBox.run();

    switch(result){
    case Gtk::RESPONSE_OK: return ResultOK;
    case Gtk::RESPONSE_YES: return ResultYes;
    case Gtk::RESPONSE_NO: return ResultNo;
    case Gtk::RESPONSE_CANCEL: return ResultCancel;
    default: return ResultOK;
    }
}

}

#endif
