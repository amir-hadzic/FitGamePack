#ifndef FITGY_VECTOR_H
#define FITGY_VECTOR_H

#include "Point.h"
#include "assert.h"
#include "math.h"

namespace Fitgy {

    /**
     * A class that represents a simple 2D vector that is usually used for
     * direction.
     */
    class Vector {
    public:
        /**
         * The X value of the vector coordinates.
         */
        float x;

        /**
         * The Y value of the vector coordinates.
         */
        float y;

        /**
         * Constructor that initializes both x and y values to 0.
         */
        Vector();

        /**
         * Constructor that initializes the vector from the provided angle.
         *
         * @param angle is used to calculate x and y values of the vector.
         */
        Vector(float angle);

        /**
         * Constuctor that initializes the x and y values with the provided
         * values.
         *
         * @param x is the value for the x property.
         * @param y is the value for the y property.
         */
        Vector(float x, float y);

        /**
         * Constructor that takes the x and y values from the provided Point.
         *
         * @see Point
         * @param point the point that will be used to initialize the vector.
         */
        Vector(Point point);

        /**
         * Sample vector that has both x and y values set to 0. Do not change
         * alter this variable!
         */
        static Vector zero;

        /**
         * Sample vector that points up. Do not alter this variable!
         */
        static Vector up;

        /**
         * Sample vector that points down. Do not alter this variable!
         */
        static Vector down;

        /**
         * Sample vector that points left. Do not alter this variable!
         */
        static Vector left;

        /**
         * Sample vector that points right. Do not alter this variable!
         */
        static Vector right;

        /**
         * Normalize the x and y values.
         */
        void normalize();

        /**
         * Rotate the vector by the specified angle.
         *
         * @param rotationAngle is the rotation angle.
         */
        void rotate(float rotationAngle);

        /**
         * Sets the X and Y values so that the vector "points" to the specified
         * point.
         *
         * @see Point
         * @param point the point at which the vector is supposed to point.
         */
        void pointAt(Point point);

        /**
         * Returns the angle that the vector represents. This should be called
         * only if the vector is normalized.
         *
         * @see normalize
         */
        float angle();

        /**
         * Implementation for the equal operator.
         */
        bool operator==(const Vector &v) const;

        /**
         * Implementation for the inequality operator.
         */
        bool operator!=(const Vector &v) const;
    };
}

#endif
