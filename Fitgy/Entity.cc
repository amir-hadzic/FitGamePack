#include "Entity.h"

namespace Fitgy {

    Entity::Entity(Entity* parent){
        entitySurface = NULL;
        externalEventHandler = NULL;
        mMouseOver = false;
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
    Entity::onMouseButtonDown(void*, SDL_Event* event, Point point){
        if (isWithinBounds(point)){
            EventHandler::onMouseButtonDown(this, event, point);

            if (externalEventHandler != NULL){
                externalEventHandler->onMouseButtonDown(this, event, point);
            }
        }
    }

    void
    Entity::onMouseButtonUp(void*, SDL_Event* event, Point point){
        if (isWithinBounds(point)){
            EventHandler::onMouseButtonUp(this, event, point);

            if (externalEventHandler != NULL){
                externalEventHandler->onMouseButtonUp(this, event, point);
            }
        }
    }

    void
    Entity::onMouseMove(void*, SDL_Event* event, Point point, Point relPoint){
        if (isWithinBounds(point + relPoint)){
            if (externalEventHandler != NULL){
                externalEventHandler->onMouseMove(this, event, point, relPoint);
            }

            if(mMouseOver == false){
                mMouseOver = true;
                onMouseEnter(this, event);
            }
        } else {
            if (mMouseOver == true){
                mMouseOver = false;
                onMouseLeave(this, event);
            }
        }
    }

    void
    Entity::onMouseEnter(void*, SDL_Event* event){
        if(externalEventHandler != NULL){
            externalEventHandler->onMouseEnter(this, event);
        }
    }

    void
    Entity::onMouseLeave(void*, SDL_Event* event){
        if(externalEventHandler != NULL){
            externalEventHandler->onMouseLeave(this, event);
        }
    }
}
