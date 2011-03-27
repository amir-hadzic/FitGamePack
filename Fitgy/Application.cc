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
    Application::Application(){
        mRunning = false;
        mDisplay = NULL;
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
                EventHub::broadcast(&event);
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

        if (Mix_Init(MIX_INIT_OGG) == 0){
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
    }

    bool
    Application::onExit(){
        mRunning = false;
        return false;
    }
}
