#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"

class FOOD_H
{
    private:
        objPos foodPos;

    public:
        Food();
        ~Food();

        generateFood(objPos blockOff);
        getFoodPos(objPos &returnPos);
}


#endif FOOD_H