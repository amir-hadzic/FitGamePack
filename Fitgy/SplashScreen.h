#ifndef FITGY_SPLASHSCREEN_H
#define FITGY_SPLASHSCREEN_H

#include <SDL/SDL.h>
#include "ImageEntity.h"

namespace Fitgy {

    class SplashScreen : public ImageEntity{
        public:
            SplashScreen(
                Entity* parent,
                char* splashImage,
                unsigned int animDuration = 2500,
                unsigned int postDuration = 1000
            );
            bool isFinished();
            void onLoop();

        private:
            unsigned short mCurrentOpacity;
            unsigned int mAnimDuration;
            unsigned int mPostDuration;
            unsigned int mLastFrameTime;
            unsigned int mPostTicks;
            unsigned int mPostStart;
            unsigned int mFrameRate;
            bool mReverse;

            bool isAnimFinished();
            bool isPostFinished();
    };
}

#endif
