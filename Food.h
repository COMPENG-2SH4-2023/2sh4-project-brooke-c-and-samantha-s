#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "GameMechs.h"

class Food
{
    private:
        objPos foodPos;
        //GameMechs *FoodMech;
        int randX;
        int randY;

        GameMechs* mainGameMechsRef;

    public:
        Food(GameMechs* thisGMRef);
        ~Food();

        void generateFood(objPos blockOff);
        void getFoodPos(objPos &returnPos);

        int getFoodX();
        int getFoodY();
        char getFoodSymbol();
};


#endif