#include "Entity.h"

namespace Fitgy {

    Entity::Entity(Entity* parent){
        entitySurface = NULL;
        externalEventHandler = NULL;

        this->parent = parent;
    }

    Entity::~Entity(){
        onCleanup();
    }

    void 
    Entity::onCleanup(){
        SDL_FreeSurface(entitySurface);
        if (externalEventHandler != NULL){
            delete externalEventHandler;
        }
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
    Entity::onRender(Entity*){

    }

    Point
    Entity::getAbsPosition(){
        if (parent == NULL){
            return position;
        }

        return position + parent->getAbsPosition();
    }

    bool
    Entity::isWithinBounds(Point point){
        Point localPoint = point - this->position;

        bool leftOfBounds = localPoint.getX() < 0 || localPoint.getY() < 0;
        bool rightOfBounds = localPoint.getX() > width || localPoint.getY() > height;

        if (leftOfBounds || rightOfBounds){
            return false;
        } else {
            return true;
        }

    }

    void
    Entity::onMouseButtonDown(SDL_Event* event, Point point){
        if (isWithinBounds(point) && externalEventHandler != NULL){
            externalEventHandler->onMouseButtonDown(event, point);
        }
    }
}
