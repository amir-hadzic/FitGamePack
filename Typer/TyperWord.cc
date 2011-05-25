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

#include "TyperWord.h"

namespace Typer {

TyperWord::TyperWord(Entity* parent, String word, TTF_Font *font)
    : Entity(parent)
{
    mUnfinishedLetters = new TextEntity(parent, word, font, Color::green());

    setWidth(mUnfinishedLetters->getWidth());
    setHeight(mUnfinishedLetters->getHeight());

    mFinishedLetters = NULL;
    mFinishedCount = 0;
    mWord = word;
    mFont = font;
}

TyperWord::~TyperWord(){
    delete mFinishedLetters;
    delete mUnfinishedLetters;
}

void
TyperWord::onLoop(){
    Entity::onLoop();

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
TyperWord::onRender(Entity*){
    if (mFinishedLetters != NULL){
        mFinishedLetters->onRender(parent);
    }

    if (mUnfinishedLetters != NULL){
        mUnfinishedLetters->onRender(parent);
    }
}

bool
TyperWord::addLetter(char letter){
    bool isNextLetter = mWord[mFinishedCount] == letter;

    if (isNextLetter) {
            mFinishedCount++;
            String finishedWord = mWord.substr(0, mFinishedCount);
            String unfinishedWord = mWord.substr(mFinishedCount);

            if (mFinishedCount == 1){
                mFinishedLetters = new TextEntity(parent, finishedWord, mFont, Color::blue());
                mUnfinishedLetters->setColor(Color::white());
            }

            mFinishedLetters->setText(finishedWord);

            if (unfinishedWord != ""){
                mUnfinishedLetters->setText(unfinishedWord);
            } else {
               delete mUnfinishedLetters;
               mUnfinishedLetters = NULL;
            }

            return true;
    } else {
        mFinishedCount = 0;
        delete mFinishedLetters;
        mFinishedLetters = NULL;

        mUnfinishedLetters->setColor(Color::green());
        mUnfinishedLetters->setText(mWord);

        return false;
    }
}

bool
TyperWord::isSolved(){
    return mFinishedCount == mWord.length();
}

String
TyperWord::getWord(){
    return mWord;
}

}
