#include "Entity.h"

namespace Fitgy {

    Entity::Entity(){
        entitySurface = NULL;
    }

    Entity::~Entity(){
        onCleanup();
    }

    void Entity::onCleanup(){
        SDL_FreeSurface(entitySurface);
    }

    void Entity::drawToSurface(SDL_Surface* surface){
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = width;
        rect.h = height;

        SDL_BlitSurface(entitySurface, NULL, surface, &rect);
    }

    void Entity::onLoop(){

    }

    void Entity::onRender(Entity* entity){

    }
}
