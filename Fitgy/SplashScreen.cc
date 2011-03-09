#include "SplashScreen.h"

namespace Fitgy {
    SplashScreen::SplashScreen(
            Entity* parent,
            char* splashImage,
            unsigned int animDuration,
            unsigned int postDuration
    )
        : ImageEntity::ImageEntity(parent, splashImage, 0)
    {
        mAnimDuration = animDuration;
        mPostDuration = postDuration;
        mCurrentOpacity = 0;
        mLastFrameTime = 0;
        mFrameRate = mAnimDuration / 51;
        mPostTicks = 0;
    }

    void
    SplashScreen::onLoop(){
        if (!isAnimFinished()){
            if (mLastFrameTime + mFrameRate > SDL_GetTicks() || isFinished()){
                return;
            }

            mLastFrameTime = SDL_GetTicks();

            mCurrentOpacity += 5;

            SDL_SetAlpha(entitySurface, SDL_SRCALPHA, mCurrentOpacity);
            return;
        }

        if (!isPostFinished()){
            mPostTicks = SDL_GetTicks() - mLastFrameTime;
        }
    }

    bool
    SplashScreen::isFinished(){
        return isAnimFinished() && isPostFinished();
    }

    bool
    SplashScreen::isAnimFinished(){
        return mCurrentOpacity >= 255;
    }

    bool
    SplashScreen::isPostFinished(){
        return mPostTicks >= mPostDuration;
    }
}
