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

#ifndef FITGY_MESSAGEBOXINT_H
#define FITGY_MESSAGEBOXINT_H

#include <string>

namespace Fitgy {

/**
 * The interface for classes that are used to show a dialog box with a message.
 */
class MessageBoxInt {
public:
    enum DialogResult {
        ResultOK,
        ResultYes,
        ResultNo,
        ResultCancel
    };

    enum Type {
        MessageInfo,
        MessageWarning,
        MessageError,
        MessageQuestion
    };

    enum Buttons {
        ButtonOK,
        ButtonOKCancel,
        ButtonYesNo
    };

    virtual DialogResult show(std::string, std::string, Type, Buttons) {
        return ResultOK;
    }
};

}

#endif
