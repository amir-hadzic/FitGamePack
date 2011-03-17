#include "Entity.h"

namespace Fitgy {

    Entity::Entity(Entity* parent){
        entitySurface = NULL;
        mExternalEventHandler = NULL;
        mMouseOver = true;
        this->parent = parent;

        EventHub::subscribe(this);
    }

    Entity::~Entity(){
        onCleanup();
    }

    void 
    Entity::onCleanup(){
        EventHub::unsubscribe(this);
        SDL_FreeSurface(entitySurface);
        if (mExternalEventHandler != NULL){
            delete mExternalEventHandler;
            mExternalEventHandler = NULL;
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
        Point localPoint = point - this->getAbsPosition();

        bool leftOfBounds = localPoint.getX() < 0 || localPoint.getY() < 0;
        bool rightOfBounds = localPoint.getX() > getWidth() || localPoint.getY() > getHeight();

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

            if (mExternalEventHandler != NULL){
                mExternalEventHandler->onMouseButtonDown(this, event, point);
            }
        }
    }

    void
    Entity::onMouseButtonUp(void*, SDL_Event* event, Point point){
        if (isWithinBounds(point)){
            EventHandler::onMouseButtonUp(this, event, point);

            if (mExternalEventHandler != NULL){
                mExternalEventHandler->onMouseButtonUp(this, event, point);
            }
        }
    }

    void
    Entity::onMouseMove(void*, SDL_Event* event, Point point, Point relPoint){
        if (isWithinBounds(point + relPoint)){
            if (mExternalEventHandler != NULL){
                mExternalEventHandler->onMouseMove(this, event, point, relPoint);
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
        if(mExternalEventHandler != NULL){
            mExternalEventHandler->onMouseEnter(this, event);
        }
    }

    void
    Entity::onMouseLeave(void*, SDL_Event* event){
        if(mExternalEventHandler != NULL){
            mExternalEventHandler->onMouseLeave(this, event);
        }
    }

    void
    Entity::setHeight(int height){
        mHeight = height;
    }

    void
    Entity::setWidth(int width){
        mWidth = width;
    }

    int
    Entity::getHeight(){
        return mHeight;
    }

    int
    Entity::getWidth(){
        return mWidth;
    }

    void
    Entity::setEventHandler(EventHandler* handler){
        mExternalEventHandler = handler;
    }

    EventHandler*
    Entity::getEventHandler(){
        return mExternalEventHandler;
    }

}
