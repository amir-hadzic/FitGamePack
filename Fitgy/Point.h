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

#ifndef FITGY_POINT_H
#define FITGY_POINT_H

#include <string>
#include <sstream>

namespace Fitgy {

    /**
     * Point is a simple class for representing a coordinate in a 2D world.
     */
    class Point {
    public:
        /**
         * The X value of the point.
         */
        float x;

        /**
         * The Y value of the point.
         */
        float y;

        /**
         * Constructor that sets the X and Y values to 0.
         */
        Point();

        /**
         * Constructor that sets the X and Y values to provided values.
         *
         * @param x the x value of the point.
         * @param y the y value of the point.
         */
        Point(float x, float y);

        /**
         * Provides an representation of the Point readable by humans.
         */
        operator std::string() const;

        bool operator==(const Point &v) const;
        bool operator!=(const Point &v) const;
        Point operator-(const Point &v) const;
        Point operator+(const Point &v) const;
        Point operator*(float scale) const;
        Point operator/(float divider) const;
        Point& operator+=(const Point &v);
        Point& operator-=(const Point &v);
        Point& operator*=(float f);
        Point& operator/=(float f);
    };
}

#endif
