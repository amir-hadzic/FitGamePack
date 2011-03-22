#include "Entity.h"

namespace Fitgy {

    Entity::Entity(Entity* parent){
        entitySurface = NULL;
        mExternalEventHandler = NULL;
        mMouseOver = true;
        this->parent = parent;
        mLastLoopTime = 0;
        mSpeed = 0;
        EventHub::subscribe(this);
    }

    Entity::~Entity(){
        onCleanup();
    }

    void 
    Entity::onCleanup(){
        EventHub::unsubscribe(this);

        if (entitySurface != NULL){
            SDL_FreeSurface(entitySurface);
            entitySurface = NULL;
        }
    }

    void 
    Entity::drawToEntity(Entity* entity){
        SDL_Rect rect;
        rect.x = position.x;
        rect.y = position.y;

        SDL_BlitSurface(entitySurface, NULL, entity->entitySurface, &rect);
    }

    void 
    Entity::onLoop(){
        float speed = getSpeed();

        if (direction != Vector::zero && speed != 0.0f && mLastLoopTime != 0){
            // Move the entity based on its direction and speed.
            unsigned int milisSinceLastLoop = SDL_GetTicks() - mLastLoopTime;
            float speedPerMilisecond = speed / 1000.0f;
            float distance = speedPerMilisecond * milisSinceLastLoop;

            position.x += direction.x * distance;
            position.y += direction.y * distance;
        }

        mLastLoopTime = SDL_GetTicks();
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

        bool leftOfBounds = localPoint.x < 0 || localPoint.y < 0;
        bool rightOfBounds = localPoint.x > getWidth() || localPoint.y > getHeight();

        if (leftOfBounds || rightOfBounds){
            return false;
        } else {
            return true;
        }

    }

    bool
    Entity::onMouseButtonDown(void*, SDL_Event* event, Point point){
        if (isWithinBounds(point)){
            EventHandler::onMouseButtonDown(this, event, point);

            if (mExternalEventHandler != NULL){
                return mExternalEventHandler->onMouseButtonDown(this, event, point);
            }
        }

        return false;
    }

    bool
    Entity::onMouseButtonUp(void*, SDL_Event* event, Point point){
        if (isWithinBounds(point)){
            EventHandler::onMouseButtonUp(this, event, point);

            if (mExternalEventHandler != NULL){
                return mExternalEventHandler->onMouseButtonUp(this, event, point);
            }
        }

        return false;
    }

    bool
    Entity::onMouseMove(void*, SDL_Event* event, Point point, Point relPoint){
        if (isWithinBounds(point + relPoint)){
            bool handled = false;
            if (mExternalEventHandler != NULL){
                handled = mExternalEventHandler->onMouseMove(this, event, point, relPoint);
            }

            if (handled){
                return true;
            }

            if(mMouseOver == false){
                mMouseOver = true;
                return onMouseEnter(this, event);
            }
        } else {
            if (mMouseOver == true){
                mMouseOver = false;
                return onMouseLeave(this, event);
            }
        }

        return false;
    }

    bool
    Entity::onMouseEnter(void*, SDL_Event* event){
        if(mExternalEventHandler != NULL){
            return mExternalEventHandler->onMouseEnter(this, event);
        }

        return false;
    }

    bool
    Entity::onMouseLeave(void*, SDL_Event* event){
        if(mExternalEventHandler != NULL){
            return mExternalEventHandler->onMouseLeave(this, event);
        }

        return false;
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

    float
    Entity::getSpeed(){
        return mSpeed;
    }

    void
    Entity::setSpeed(float speed){
        mSpeed = speed;
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
