/**
*    This file is part of FitGamePack.
*
*    FitGamePack is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    FitGamePack is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with FitGamePack.  If not, see <http://www.gnu.org/licenses/>.
*
*    Author: Amir Hadzic <amir.hadzic@randomshouting.com>
*/

#ifndef FITGY_ENTITY_H
#define FITGY_ENTITY_H

#include "LibSDL.h"
#include <vector>
#include "Point.h"
#include "Vector.h"
#include "EventHandler.h"
#include "EventHub.h"
#include <iostream>

namespace Fitgy {

class Entity : public EventHandler {
protected:
    static int numEntities;
    /**
     * Holds the hover state. If this is true then the cursor position is
     * within the entity bounds.
     *
     * This is used for firing the onMouseEnter and onMouseLeave events.
     */
    bool mMouseOver;

    /**
     * Entity's width.
     */
    unsigned int mWidth;

    /**
     * Entity's height.
     */
    unsigned int mHeight;

    /**
     * The moving speed of the Entity.
     */
    float mSpeed;

    /**
     * This is the time (in miliseconds) when the onLoop method was called
     * the last time.
     */
    unsigned int mLastLoopTime;

    /**
     * This is the event handler that receives some localized events of the
     * Entity such as onMouseEnter, onMouseLeave, onMouseMove,
     * onMouseButtonDown, etc.
     */
    EventHandler* mExternalEventHandler;

    Entity(Entity const&){};
    Entity& operator=(Entity const&){ return *this; };

    /**
     * Simply blits entity's surface to the specified entity's surface.
     *
     * Both the entitySurface of this entity and the destination entity
     * need to be initialized.
     *
     * @param entity is the entity that holds the destination surface.
     */
    void drawToEntity(Entity* entity);

public:
    /**
     * The current position of this entity relative to his parent.
     */
    Point position;

    /**
     * The SDL_Surface structure that belongs to this entity.
     */
    SDL_Surface* entitySurface;

    /**
     * The direction in which the Entity will move if the getSpeed() method
     * returns some value larger than 0.
     */
    Vector direction;

    /**
     * The parent entity.
     */
    Entity* parent;

    /**
     * Initializes the Entity with the provided parent Entity.
     *
     * Entity should always be inherited as this constructor sets the
     * entitySurface to NULL and as such can't be rendered as there is
     * nothing to render.
     */
    Entity(Entity* parent = NULL);

    /**
     * The destructor.
     */
    virtual ~Entity();

    /**
     * onLoop() is in charge of operations like moving the entity,
     * controlling its speed and direction, etc.
     *
     * This method should be called by the Application or by the Parent
     * entity, depending on who created the instance.
     */
    virtual void onLoop();

    /**
     * onRender() is in charge of rendering the entity onto the Parent
     * entity.
     *
     * This method should be called by the Application or by the Parent
     * entity, depending on who created the instance.
     *
     * @see drawToEntity
     */
    virtual void onRender(Entity* entity);

    /**
     * onCleanup() is called from the destructor and it should clean
     * all allocated resources by the entity.
     *
     * It's recommended to implement the cleaning code in the destructor
     * if you wish to inherit this class.
     */
    virtual void onCleanup();

    /**
     * Returns the absolute position of the Entity.
     *
     * @return the absolute position of this Entity as Point.
     */
    Point getAbsPosition();

    /**
     * Checks if the provided point is within the bounds of this Entity.
     *
     * @param point is the absolute point that needs to be checked.
     * @return true if the point is within the boundaries of this Entity.
     */
    bool isWithinBounds(Point point);

    /**
     * Implementation for the onMouseButtonDown event.
     */
    bool onMouseButtonDown(void* sender, SDL_Event* event, Point point);

    /**
     * Implementation for the onMouseButtonUp event.
     */
    bool onMouseButtonUp(void* sender, SDL_Event* event, Point point);

    /**
     * Implementation for the onMouseButtonUp event.
     */
    bool onMouseMove(void* sender, SDL_Event* event, Point point, Point relPoint);

    /**
     * Implementation for the onMouseButtonUp event.
     */
    bool onMouseEnter(void* sender, SDL_Event* event);

    /**
     * Implementation for the onMouseButtonUp event.
     */
    bool onMouseLeave(void* sender, SDL_Event* event);

    /**
     * Sets the height.
     *
     * @param height is the height of this Entity.
     */
    virtual void setHeight(int height);

    /**
     * Get the height.
     *
     * @return the height of this Entity.
     */
    virtual int getHeight();

    /**
     * Sets the width.
     *
     * @param width is the width of this Entity.
     */
    virtual void setWidth(int width);

    /**
     * Get the width
     *
     * @return the width of this Entity.
     */
    virtual int getWidth();

    /**
     * Set the speed.
     *
     * @param speed is the speed of this Entity.
     */
    virtual void setSpeed(float speed);

    /**
     * Get the speed.
     *
     * If this method returns a value greater than 0 and the direction
     * property is not Vector::zero then this Entity is going to start
     * moving.
     *
     * @return the speed of this Entity.
     */
    virtual float getSpeed();

    /**
     * Sets the external event handler.
     *
     * You are responsible of deleting this event handler instance
     * after it's no longer neccesary.
     * @param handler is the external event handler.
     */
    virtual void setEventHandler(EventHandler* handler);

    /**
     * Gets the external event handler.
     *
     * @return the external event handler instance if any is set.
     */
    virtual EventHandler* getEventHandler();

    /**
     * Gets the top left position of this entity.
     *
     * @return top left position of this entity.
     */
    Point topLeft();

    /**
     * Gets the top right position of this entity.
     *
     * @return top right position of this entity.
     */
    Point topRight();

    /**
     * Gets the bottom left position of this entity.
     *
     * @return bottom left position of this entity.
     */
    Point bottomLeft();

    /**
     * Gets the bottom right position of this entity.
     *
     * @return bottom right position of this entity.
     */
    Point bottomRight();
};

}

#endif
