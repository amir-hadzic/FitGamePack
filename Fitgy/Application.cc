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

#include "Application.h"

namespace Fitgy {

Application::Music::Music(char* filename, short volume){
    mVolume = volume;

    mMixMusic = Mix_LoadMUS(filename);
    if (!mMixMusic){
        throw Exception::FileNotFound(filename);
    }

    mPaused = false;
    Mix_VolumeMusic(volume);
}

Application::Music::~Music(){
    stop();
    Mix_FreeMusic(mMixMusic);
}

void
Application::Music::play(int loops){
    if (mPaused){
        Mix_ResumeMusic();
        mPaused = false;
    } else {
        Mix_PlayMusic(mMixMusic, loops);
    }
}

void
Application::Music::pause(){
    Mix_PauseMusic();
    mPaused = true;
}

void
Application::Music::stop(){
    Mix_HaltMusic();
    mPaused = false;
}

void
Application::Music::setVolume(short volume){
    mVolume = volume;
    Mix_VolumeMusic(volume);
}

Application::Application(){
    mRunning = false;
    mDisplay = NULL;
    mMusic = NULL;
}

Application::~Application(){
}

Display*
Application::getDisplay(){
    return mDisplay;
}

void
Application::addEntity(Entity* entity){
    mEntities.push_back(entity);
}

void
Application::removeEntity(Entity* entity){
    EntityIterator it = std::find(mEntities.begin(), mEntities.end(), entity);

    if (it != mEntities.end()){
        delete (*it);
        mEntities.erase(it);
    }
}

int
Application::execute(){
    mRunning = true;

    if (init() == false){
        return -1;
    }
    
    SDL_Event event;
    while(mRunning){
        while(SDL_PollEvent(&event)){
            EventHub::broadcast(event);
            onEvent(this, &event);
        }

        loop();
        startRender();
    }

    cleanup();

    return 0;
}

bool
Application::init(){
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        return false;
    }

    SDL_EnableUNICODE(1);

    if (TTF_Init() < 0){
        return false;
    }

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,
            MIX_AUDIO_CHANNELS, MIX_CHUNKSIZE) == -1)
    {
        return false;
    }

    Mix_AllocateChannels(MIX_NUM_CHANNELS);

    mDisplay = new Display(640, 480);
    return true;
}

void
Application::loop(){
    EntityIterator it = mEntities.begin();

    while(it != mEntities.end()){
        (*it)->onLoop();
        ++it;
    }
}

void
Application::startRender(){
    SDL_FillRect(mDisplay->entitySurface, NULL, 0);

    render();

    SDL_Flip(mDisplay->entitySurface);
}

void
Application::render(){
    EntityIterator it = mEntities.begin();

    while(it != mEntities.end()){
        (*it)->onRender(mDisplay);
        ++it;
    }
}

void
Application::cleanup(){
    EntityIterator it = mEntities.begin();

    while(it != mEntities.end()){
        delete (*it);
        *it = NULL;
        it = mEntities.erase(it);
    }

    delete mDisplay;
    delete mMusic;
}

bool
Application::onExit(){
    mRunning = false;
    return false;
}

Application::Music*
Application::music(){
    return mMusic;
}

void
Application::setMusic(char* filename, short volume){
    if (mMusic != NULL){
        delete mMusic;
        mMusic = NULL;
    }

    mMusic = new Application::Music(filename, volume);
}
}
