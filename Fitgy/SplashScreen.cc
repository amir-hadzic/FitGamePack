/**
*    This file is part of FitGamePack.
*
*    FitGamePack is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    FitGamePack is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with FitGamePack.  If not, see <http://www.gnu.org/licenses/>.
*
*    Author: Amir Hadzic <amir.hadzic@randomshouting.com>
*/

#include "SplashScreen.h"

namespace Fitgy {
    SplashScreen::SplashScreen(
            Entity* parent,
            char* splashImage,
            unsigned int animDuration,
            unsigned int postDuration
    )
        : ImageEntity(parent, splashImage, 0)
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
