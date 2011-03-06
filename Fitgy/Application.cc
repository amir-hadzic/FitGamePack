#include "Application.h"

namespace Fitgy {

    Application::Application(){
        mRunning = false;
        mDisplay = NULL;
    }
    
    int Application::execute(){
        mRunning = true;
        
        if (init() == false){
            return -1;
        }
        
        SDL_Event event;
        while(mRunning){
            while(SDL_PollEvent(&event)){
                onEvent(&event);
            }

            loop();
            render();
        }
        
        cleanup();
        
        return 0;
    }
    
    bool Application::init(){
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
            return false;
        }

        mDisplay = new Display(640, 480);
        return true;
    }
    
    void Application::loop(){

    }
    
    void Application::render(){
        for(int i = 0; i < mEntities.size(); i++){
            mEntities[i]->onRender(mDisplay);
        }
    }
    
    void Application::cleanup(){
            
    }

    void Application::onEvent(SDL_Event* event)
    {
        EventHandler::onEvent(event);
    }

    void Application::onExit(){
        mRunning = false;
    }
}
