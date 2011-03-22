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
