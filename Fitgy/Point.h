#ifndef FITGY_POINT_H
#define FITGY_POINT_H

#include <string>
#include <sstream>

namespace Fitgy {

    class Point {
    public:
        float x;
        float y;

        Point();
        Point(float x, float y);

        Point operator+(const Point point);
        Point operator-(const Point point);
        operator std::string() const;
    };
}

#endif
