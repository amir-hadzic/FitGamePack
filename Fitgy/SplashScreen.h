#ifndef FITGY_SPLASHSCREEN_H
#define FITGY_SPLASHSCREEN_H

#include "LibSDL.h"
#include "ImageEntity.h"

namespace Fitgy {

    /**
     * An entity that can be used as a splash screen in games.
     */
    class SplashScreen : public ImageEntity{
    public:
        /**
         * Constructor that initializes the splash screen.
         *
         * @param parent is the parent entity.
         * @param splashImage is the path to the image that will be used as a
         * splash screen. Make sure that this image fills the whole screen.
         * @param animDuration is the duration of the "fade in" animation.
         * @param postDuration is the time that the splash screen should stay
         * active after the "fade in" animation is finished.
         *
         * @see Entity
         */
        SplashScreen(Entity* parent, char* splashImage,
                unsigned int animDuration = 2500,
                unsigned int postDuration = 1000);

        /**
         * Checks if the splash screen is considered to be finished.
         *
         * @return A bool value indicating whether the splash screen is finished.
         */
        bool isFinished();

        /**
         * Implementation for the onLoop method. This method is supposed to be
         * called by the parent Entity or by the Application, depending on who
         * created it.
         *
         * @see Entity
         * @see Application
         */
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

        /**
         * Checks if the "fade in" animation is finished.
         *
         * @return A bool value indicating whether the "fade in" animation is
         * finished.
         */
        bool isAnimFinished();

        /**
         * Checks if the wait time after the "fade in" animation is finished.
         *
         * @return A bool value indicating whether the time after the "fade in"
         * animation is finished.
         */
        bool isPostFinished();
    };
}

#endif
