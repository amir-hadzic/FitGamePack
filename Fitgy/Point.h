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
         * Implementation for the + operator.
         */
        Point operator+(const Point point);

        /**
         * Implementation for the - operator.
         */
        Point operator-(const Point point);

        /**
         * Provides an representation of the Point readable by humans.
         */
        operator std::string() const;
    };
}

#endif
