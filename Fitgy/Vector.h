#ifndef FITGY_VECTOR_H
#define FITGY_VECTOR_H

#include "Point.h"
#include "assert.h"
#include "math.h"

namespace Fitgy {

    class Vector {
    public:
        float x;
        float y;

        Vector();
        Vector(float angle);
        Vector(float x, float y);
        Vector(Point point);

        static Vector zero;
        static Vector up;
        static Vector down;
        static Vector left;
        static Vector right;

        void normalize();
        void rotate(float rotationAngle);
        void pointAt(Point point);
        float angle();

        bool operator==(const Vector &v) const;
        bool operator!=(const Vector &v) const;
    };
}

#endif
