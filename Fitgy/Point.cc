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

#include "Point.h"

namespace Fitgy {

    Point::Point(){
        x = 0;
        y = 0;
    }

    Point::Point(float x, float y){
        this->x = x;
        this->y = y;
    }

    Point
    Point::operator+(Point point){
        Point result(x + point.x, y + point.y);
        return result;
    }

    Point
    Point::operator-(Point point){
        Point result(x - point.x, y - point.y);
        return result;
    }

    Point::operator std::string() const {
        std::stringstream ss;
        ss << "(" << x << ", " << y << ")";

        return ss.str();
    }
}
