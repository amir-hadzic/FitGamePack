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
