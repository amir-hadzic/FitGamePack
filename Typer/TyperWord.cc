#include "TyperWord.h"
#include <iostream>

namespace Typer {

    TyperWord::TyperWord(Fitgy::Entity* parent, std::string word, TTF_Font *font)
        : Fitgy::Entity::Entity(parent)
    {
        mUnfinishedLetters = new Fitgy::TextEntity(parent, word, font,
                Fitgy::Color::green());

        setWidth(mUnfinishedLetters->getWidth());
        setHeight(mUnfinishedLetters->getHeight());

        mFinishedLetters = NULL;
        mFinishedCount = 0;
        mWord = word;
        mFont = font;
    }

    TyperWord::~TyperWord(){
        if (mFinishedLetters != NULL){
            delete mFinishedLetters;
            mFinishedLetters = NULL;
        }

        if (mUnfinishedLetters != NULL){
            delete mUnfinishedLetters;
            mUnfinishedLetters = NULL;
        }
    }

    void
    TyperWord::onLoop(){
        Fitgy::Entity::onLoop();

        if (mUnfinishedLetters != NULL){
            mUnfinishedLetters->position = this->position;
        }

        if (mFinishedLetters != NULL){
            mFinishedLetters->position = this->position;

            if (mUnfinishedLetters != NULL){
                mUnfinishedLetters->position.x += mFinishedLetters->getWidth();
            }
        }
    }

    void
    TyperWord::onRender(Entity* entity){
        if (mFinishedLetters != NULL){
            mFinishedLetters->onRender(parent);
        }

        if (mUnfinishedLetters != NULL){
            mUnfinishedLetters->onRender(parent);
        }
    }

    bool
    TyperWord::onKeyDown(SDLKey sym, SDLMod mod, uint16_t unicode){
        bool hit = mWord[mFinishedCount] == (char)unicode;

        if (isSolved()){
            return false;
        }

        if (hit) {
            mFinishedCount++;
            std::string finishedWord = mWord.substr(0, mFinishedCount);
            std::string unfinishedWord = mWord.substr(mFinishedCount);

            if (mFinishedCount == 1){
                mFinishedLetters = new Fitgy::TextEntity(parent, finishedWord,
                        mFont, Fitgy::Color::blue());
            }

            mFinishedLetters->setText(finishedWord);

            if (unfinishedWord != ""){
                mUnfinishedLetters->setText(unfinishedWord);
            } else {
                delete mUnfinishedLetters;
                mUnfinishedLetters = NULL;
            }
        } else {
            mFinishedCount = 0;
            delete mFinishedLetters;
            mFinishedLetters = NULL;

            mUnfinishedLetters->setText(mWord);
        }

        return false;
    }

    bool
    TyperWord::isSolved(){
        return mFinishedCount == mWord.length();
    }
}
