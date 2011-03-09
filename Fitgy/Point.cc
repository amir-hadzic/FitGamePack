#include "Point.h"

namespace Fitgy {

    Point::Point(){
        mX = 0;
        mY = 0;
    }

    Point::Point(float x, float y){
        mX = x;
        mY = y;
    }

    void
    Point::setX(float value){
        mX = value;
    }

    float
    Point::getX(){
        return mX;
    }

    void
    Point::setY(float value){
        mY = value;
    }

    float
    Point::getY(){
        return mY;
    }

    Point
    Point::operator+(Point point){
        Point result(getX() + point.getX(), getY() + point.getY());
        return result;
    }

    Point
    Point::operator-(Point point){
        Point result(getX() - point.getX(), getY() - point.getY());
        return result;
    }
}
