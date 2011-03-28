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

#include "Sound.h"

namespace Fitgy {

    Sound::Sound(char* filename, short volume, short channel){
        mChunk = Mix_LoadWAV(filename);
        mChannel = channel;
        mVolume = volume;
        mLoops = 0;
        mPaused = false;

        Mix_VolumeChunk(mChunk, mVolume);
    }

    Sound::~Sound(){
        stop();
        Mix_FreeChunk(mChunk);
    }

    void
    Sound::play(){
        if (mPaused){
            Mix_Resume(mChannel);
            mPaused = false;
        } else {
            mChannel = Mix_PlayChannel(mChannel, mChunk, mLoops);
        }
    }

    void
    Sound::pause(){
        Mix_Pause(mChannel);
        mPaused = true;
    }

    void
    Sound::stop(){
        Mix_HaltChannel(mChannel);
        mPaused = false;
    }

    void
    Sound::setLoops(int loops){
        mLoops = loops;
    }

    int
    Sound::getLoops(){
        return mLoops;
    }

    void
    Sound::setVolume(short volume){
        mVolume = volume;

        Mix_VolumeChunk(mChunk, mVolume);
    }

    short
    Sound::getVolume(){
        return mVolume;
    }
}
