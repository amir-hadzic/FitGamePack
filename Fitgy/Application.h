#ifndef FITGY_APPLICATION_H
#define FITGY_APPLICATION_H

#include <SDL/SDL.h>
#include "EventHandler.h"
#include "Entity.h"
#include "Display.h"
#include <vector>

namespace Fitgy {
    
    class Application : public EventHandler {
        private:
            bool mRunning;
            Display* mDisplay;
            std::vector<Entity*> mEntities;
            
        public:
            Application();
            int execute();
            bool init();
            void loop();
            void render();
            void cleanup();
            void onExit();
            void onEvent(SDL_Event* event);
    };
}

#endif
