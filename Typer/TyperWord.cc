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
#include <iostream>

namespace Typer {

    TyperWord::TyperWord(Fitgy::Entity* parent, std::string word, TTF_Font *font)
        : Entity(parent)
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
    TyperWord::onRender(Entity*){
        if (mFinishedLetters != NULL){
            mFinishedLetters->onRender(parent);
        }

        if (mUnfinishedLetters != NULL){
            mUnfinishedLetters->onRender(parent);
        }
    }

    bool
    TyperWord::onKeyDown(SDLKey, SDLMod, uint16_t unicode){
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
                mUnfinishedLetters->setColor(Fitgy::Color::white());
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

            mUnfinishedLetters->setColor(Fitgy::Color::green());
            mUnfinishedLetters->setText(mWord);
        }

        return false;
    }

    bool
    TyperWord::isSolved(){
        return mFinishedCount == mWord.length();
    }
}