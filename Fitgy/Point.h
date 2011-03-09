#ifndef FITGY_POINT_H
#define FITGY_POINT_H

namespace Fitgy {

    class Point {
        private:
            float mX;
            float mY;

        public:
            Point();
            Point(float x, float y);

            void setY(float value);
            float getY();

            void setX(float value);
            float getX();

            Point operator+(const Point point);
            Point operator-(const Point point);
    };
}

#endif
