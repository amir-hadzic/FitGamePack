#include "GridEntity.h"
#include "assert.h"

namespace Fitgy {
    GridEntity::GridEntity(Entity* parent, int width, int height, int dimension)
        : Entity(parent)
    {
        assert(dimension > 0);

        mDimension = dimension;
        mFieldWidth = width / dimension;
        mFieldHeight = height / dimension;

        mBackgroundColor.r = 0xaa;
        mBackgroundColor.g = 0xaa;
        mBackgroundColor.b = 0xaa;
        mBackgroundImage = NULL;

        mWidth = width;
        mHeight = height;

        entitySurface = SDL_CreateRGBSurface(
            SDL_HWSURFACE, width, height, 32, 0, 0, 0, 0
        );
    }

    GridEntity::~GridEntity()
    {
        // Delete each entity and call their destructors.
        mFields.clear();
        onCleanup();
    }

    void
    GridEntity::onRender(Entity* entity){
        // TODO: Maybe the surface shouldn't be refilled each time
        // render() is called.
        SDL_FillRect(
            entitySurface,
            NULL,
            SDL_MapRGB(
                entitySurface->format,
                mBackgroundColor.r,
                mBackgroundColor.g,
                mBackgroundColor.b
            )
        );

        if (mBackgroundImage != NULL){
            mBackgroundImage->onRender(this);
        }

        std::map<int, Entity*>::iterator it;
        for(it = mFields.begin(); it != mFields.end(); it++){
            (*it).second->onRender(this);
        }

        drawToEntity(entity);
    }

    void
    GridEntity::addEntity(Entity* entity, int field){
        entity->position.setX((field % mDimension) * mFieldWidth);
        entity->position.setY((field / mDimension) * mFieldHeight);
        mFields[field] = entity;
    }

    void
    GridEntity::removeEntity(int field){
        mFields.erase(field);
    }

    void
    GridEntity::setBackground(SDL_Color color){
        mBackgroundColor = color;
    }

    void
    GridEntity::setBackground(ImageEntity* imageEntity){
        mBackgroundImage = imageEntity;
    }

    void
    GridEntity::onEvent(void* sender, SDL_Event *event){
        Entity::onEvent(sender, event);

        std::map<int, Entity*>::iterator it;
        for(it = mFields.begin(); it != mFields.end(); it++){
            (*it).second->onEvent((*it).second, event);
        }
    }
}
