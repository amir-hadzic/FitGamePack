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

#include "MessageBox.h"

namespace Fitgy {

MessageBox::MessageBoxWin::DialogResult
MessageBox::MessageBoxWin::show(std::string message, std::string title,
        Type type, Buttons buttons)
{
    Gtk::Main kit(0, NULL);

    unsigned int messageType = 0;
    switch(type){
    case MessageInfo:
        messageType = MB_ICONINFORMATION;
        break;
    case MessageWarning:
        messageType = MB_ICONWARNING;
        break;
    case MessageQuestion:
        messageType = MB_ICONQUESTION;
        break;
    case MessageError:
        messageType = MB_ICONERROR;
        break;
    default:
        messageType = MB_ICONINFORMATION;
    }

    switch(buttons){
    case ButtonOK:
        messageType |= MB_OK;
        break;
    case ButtonOKCancel:
        messageType |= MB_OKCANCEL;
        break;
    case ButtonYesNo:
        messageType |= MB_YESNO;
        break;
    default:
        messageType = MB_OK;
    }

    messageType |= MB_TASKMODAL;
    int result = MessageBox(NULL, message, title, messageType);

    switch(result){
    case IDOK: return ResultOK;
    case IDYES: return ResultYes;
    case IDNO: return ResultNo;
    case IDCANCEL: return ResultCancel;
    default: return ResultOK;
    }
}

}

#endif
