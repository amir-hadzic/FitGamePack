#ifndef FITGY_SPLASHSCREEN_H
#define FITGY_SPLASHSCREEN_H

#include <SDL/SDL.h>
#include "ImageEntity.h"

namespace Fitgy {

    class SplashScreen : public ImageEntity{
        public:
            SplashScreen(
                char* splashImage,
                int animDuration = 2500,
                int postDuration = 1000
            );
            bool isFinished();
            void onLoop();

        private:
            short mCurrentOpacity;
            int mAnimDuration;
            int mPostDuration;
            int mLastFrameTime;
            int mPostTicks;
            int mPostStart;
            int mFrameRate;
            bool mReverse;

            bool isAnimFinished();
            bool isPostFinished();
    };
}

#endif
