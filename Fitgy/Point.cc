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
