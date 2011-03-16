#ifndef FITGY_DISPLAY_H
#define FITGY_DISPLAY_H

#include "Entity.h"
#include <string>

namespace Fitgy {

    class Display: public Entity {
        public:
            Display(int width, int height);
            void setTitle(char* windowTitle, char* iconTitle);
    };
}

#endif
