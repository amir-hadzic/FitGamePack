#include "FieldImageEntity.h"

namespace Fitgy {
    FieldImageEntity::FieldImageEntity(Entity* parent, char* filename, int field, short opacity)
        : ImageEntity::ImageEntity(parent, filename, opacity)
    {
        mField = field;
    }

    int FieldImageEntity::getField(){
        return mField;
    }
}
