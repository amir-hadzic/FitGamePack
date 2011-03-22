#ifndef FITGY_APPLICATION_H
#define FITGY_APPLICATION_H

#include "LibSDL.h"
#include "EventHandler.h"
#include "EventHub.h"
#include "Entity.h"
#include "Display.h"
#include <vector>
#include <algorithm>

namespace Fitgy {
    typedef std::vector<Entity*> EntityContainer;
    typedef EntityContainer::iterator EntityIterator;

    class Application : public EventHandler {
    private:
        bool mRunning;

    protected:
        std::vector<Entity*> mEntities;
        Display* mDisplay;
        void startRender();

    public:
        Application();
        ~Application();
        int execute();
        Display* getDisplay();
        void addEntity(Entity* entity);
        void removeEntity(Entity* entity);

        virtual bool init();
        virtual void loop();
        virtual void render();
        virtual void cleanup();
        virtual bool onExit();
    };
}

#endif
