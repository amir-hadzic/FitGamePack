#ifndef FITGY_FIELDIMAGEENTITY_H
#define FITGY_FIELDIMAGEENTITY_H

#include "ImageEntity.h"

namespace Fitgy {

    class FieldImageEntity : public ImageEntity {
        private:
            int mField;
        public:
            FieldImageEntity(Entity* parent, char* filename, int field, short opacity = SDL_ALPHA_OPAQUE);
            int getField();
    };
}

#endif
