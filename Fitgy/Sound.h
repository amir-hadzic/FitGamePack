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

#include "LibSDL.h"

namespace Fitgy {

    class Sound {
    private:
        Mix_Chunk* mChunk;
        short mChannel;
        short mVolume;
        int mLoops;
        bool mPaused;

    public:
        /**
         * Constructor.
         *
         * @param filename is the path to the sound file.
         * @param volume is the volume of the sound when played. This value
         * should be between 0 and MIX_MAX_VOLUME (128).
         * @param channel is the channel number on which this sound is going to
         * be played. If this is set to -1 the first free channel will be used.
         */
        Sound(char* filename, short volume = MIX_MAX_VOLUME, short channel = -1);

        /**
         * Destructor.
         */
        ~Sound();

        /**
         * Plays the sound.
         */
        void play();

        /**
         * Pauses the sound.
         */
        void pause();

        /**
         * Stops the sound
         */
        void stop();

        /**
         * Sets the number of play loops.
         *
         * @param loops is the number of loops the sample should be played when
         * play() is called. For example, if you pass the value of 1, the sample
         * will be played two times (loops + 1). If this value is set to 0 the
         * sound will be played only once when play() is called. If this value
         * is set to -1 the sound will be played until pause() is called.
         */
        void setLoops(int loops);

        /**
         * Gets the number of play loops.
         *
         * @return the number of times the sound will be repeated when play() is
         * called.
         *
         * @see setLoops
         * @see play
         */
        int getLoops();

        /**
         * Sets the volume.
         *
         * @param volume is the volume of the sound.
         */
        void setVolume(short volume);

        /**
         * Gets the volume.
         *
         * @return the volume of this sound.
         */
        short getVolume();
    };
}
