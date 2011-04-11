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

#include "Vector.h"

namespace Fitgy {

    Vector Vector::zero(0, 0);
    Vector Vector::up(0, -1);
    Vector Vector::down(0, 1);
    Vector Vector::left(-1, 0);
    Vector Vector::right(1, 0);

    Vector::Vector(){
        x = 0;
        y = 0;
    }

    Vector::Vector(float angle){
        x = cos(angle);
        y = sin(angle);
    }

    Vector::Vector(float x, float y){
        this->x = x;
        this->y = y;
    }

    Vector::Vector(Point point){
        x = point.x;
        y = point.y;
    }

    void
    Vector::normalize(){
        float magnitude = sqrt((x * x) + (y * y));
        assert(magnitude != 0.0f);

        x /= magnitude;
        y /= magnitude;
    }

    float
    Vector::angle(){
        return atan2(y, x);
    }

    void
    Vector::rotate(float rotationAngle){
        float angleToSet = angle() + rotationAngle;
        x = cos(angleToSet);
        y = sin(angleToSet);
    }

    void
    Vector::pointAt(Point point){
        x = point.x;
        y = point.y;

        normalize();
    }

    bool
    Vector::operator==(const Vector &vector) const {
        return x == vector.x && y == vector.y;
    }

    bool
    Vector::operator!=(const Vector &vector) const {
        return !(*this == vector);
    }

    Vector
    Vector::operator-() const {
        return Vector::zero - *this;
    }

    Vector
    Vector::operator-(const Vector &v) const {
        return Vector(x - v.x, y - v.y);
    }

    Vector
    Vector::operator+(const Vector &v) const {
        return Vector(x + v.x, y + v.y);
    }

    Vector
    Vector::operator*(float scale) const {
        return Vector(x * scale, y * scale);
    }

    Vector
    Vector::operator/(float divider) const {
        return Vector(x / divider, y / divider);
    }

    Vector&
    Vector::operator+=(const Vector &v) {
        x += v.x;
        y += v.y;

        return *this;
    }

    Vector&
    Vector::operator-=(const Vector &v) {
        x -= v.x;
        y -= v.y;

        return *this;
    }

    Vector&
    Vector::operator*=(float f) {
        x *= f;
        y *= f;

        return *this;
    }

    Vector&
    Vector::operator/=(float f) {
        x /= f;
        y /= f;

        return *this;
    }
}
