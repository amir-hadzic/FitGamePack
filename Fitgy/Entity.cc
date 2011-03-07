#include "Entity.h"

namespace Fitgy {

    Entity::Entity(){
        entitySurface = NULL;
    }

    Entity::~Entity(){
        onCleanup();
    }

    void 
    Entity::onCleanup(){
        SDL_FreeSurface(entitySurface);
    }

    void 
    Entity::drawToEntity(Entity* entity){
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;

        SDL_BlitSurface(entitySurface, NULL, entity->entitySurface, &rect);
    }

    void 
    Entity::onLoop(){

    }

    void 
    Entity::onRender(Entity* entity){

    }
}
