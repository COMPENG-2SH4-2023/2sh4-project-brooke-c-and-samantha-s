#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "GameMechs.h"

class Food
{
    private:
        objPos foodPos;
        objPosArrayList* foodBucket;
        int randX;
        int randY;

        GameMechs* mainGameMechsRef;

    public:
        Food(GameMechs* thisGMRef);
        ~Food();

        void generateFood(objPosArrayList* blockOff);
        void getFoodPos(objPos &returnPos);
        objPosArrayList* getFoodList();

        int getFoodX();
        int getFoodY();
        char getFoodSymbol();
};


#endif