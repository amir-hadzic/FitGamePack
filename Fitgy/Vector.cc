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
}
