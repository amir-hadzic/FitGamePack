#include "FieldImageEntity.h"

namespace Fitgy {
    FieldImageEntity::FieldImageEntity(Entity* parent, char* filename, int field, short opacity)
        : ImageEntity(parent, filename, opacity)
    {
        mField = field;
    }

    int FieldImageEntity::getField(){
        return mField;
    }

    bool FieldImageEntity::onMouseMove(void* sender, SDL_Event* event, Point point, Point relPoint){
        return ImageEntity::onMouseMove(sender, event, point, relPoint);
    }

    bool FieldImageEntity::onMouseEnter(void* sender, SDL_Event* event){
        return ImageEntity::onMouseEnter(sender, event);
    }
}
