#ifndef FITGY_APPLICATION_H
#define FITGY_APPLICATION_H

#include "LibSDL.h"
#include "EventHandler.h"
#include "EventHub.h"
#include "Entity.h"
#include "Display.h"
#include <vector>

namespace Fitgy {
    
    class Application : public EventHandler {
        private:
            bool mRunning;

        protected:
            std::vector<Entity*> mEntities;
            Display* mDisplay;
            void startRender();
            
        public:
            Application();
            int execute();
            virtual bool init();
            virtual void loop();
            virtual void render();
            virtual void cleanup();
            virtual bool onExit();
    };
}

#endif
