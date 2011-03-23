#ifndef FALLINGWORD_H
#define FALLINGWORD_H

#include "../Fitgy/Fitgy.h"
#include <string>

namespace Typer {

    class TyperWord : public Fitgy::Entity {
    private:
        Fitgy::TextEntity* mFinishedLetters;
        Fitgy::TextEntity* mUnfinishedLetters;
        unsigned short mFinishedCount;
        std::string mWord;
        TTF_Font* mFont;

    public:
        TyperWord(Fitgy::Entity* parent, std::string word, TTF_Font* font);
        ~TyperWord();

        void onRender(Fitgy::Entity* entity);
        void onLoop();
        bool onKeyDown(SDLKey sym, SDLMod mod, uint16_t unicode);
        bool isSolved();
    };
}

#endif
