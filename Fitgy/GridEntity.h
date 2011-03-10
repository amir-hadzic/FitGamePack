#ifndef FITGY_GRIDENTITY_H
#define FITGY_GRIDENTITY_H

#include <SDL/SDL.h>
#include <vector>
#include <map>
#include "Entity.h"
#include "ImageEntity.h"

namespace Fitgy {

    class GridEntity : public Entity {
        private:
            std::map<int, Entity*> mFields;
            int mFieldWidth;
            int mFieldHeight;
            int mDimension;
            SDL_Color mBackgroundColor;
            ImageEntity *mBackgroundImage;

        public:
            GridEntity(Entity* parent, int width, int height, int dimension);
            ~GridEntity();

            void onRender(Entity* entity);
            void onEvent(void* sender, SDL_Event* event);

            void addEntity(Entity* entity, int field);
            void removeEntity(int field);
            void setBackground(SDL_Color color);
            void setBackground(ImageEntity *imageEntity);
    };
}

#endif
