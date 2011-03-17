#include "Application.h"

namespace Fitgy {
    Application::Application(){
        mRunning = false;
        mDisplay = NULL;
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

        if (TTF_Init() < 0){
            return false;
        }

        mDisplay = new Display(640, 480);
        return true;
    }
    
    void 
    Application::loop(){
        for(unsigned int i = 0; i < mEntities.size(); i++){
            mEntities[i]->onLoop();
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
        for(unsigned int i = 0; i < mEntities.size(); i++){
            mEntities[i]->onRender(mDisplay);
        }
    }
    
    void 
    Application::cleanup(){
            
    }

    void 
    Application::onExit(){
        mRunning = false;
    }
}
