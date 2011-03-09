#include "Entity.h"

namespace Fitgy {

    Entity::Entity(Entity* parent){
        entitySurface = NULL;
        this->parent = parent;
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
        rect.x = position.getX();
        rect.y = position.getY();

        SDL_BlitSurface(entitySurface, NULL, entity->entitySurface, &rect);
    }

    void 
    Entity::onLoop(){

    }

    void 
    Entity::onRender(Entity* entity){

    }
}
