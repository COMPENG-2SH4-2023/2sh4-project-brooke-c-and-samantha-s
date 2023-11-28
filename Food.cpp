#include "Food.h"
#include "GameMechs.h"
#include "objPos.h"

Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    //foodPos.setObjPos(2, 2, 'x');
}

Food::~Food()
{
    //delete Food;
}

void Food::generateFood(objPos blockOff)
{
    do{
        randX = (rand() % mainGameMechsRef->getBoardSizeX())+1; // generates random positions
        randY = (rand() % mainGameMechsRef->getBoardSizeY())+1;
    }while(randX == blockOff.x && randY == blockOff.y);
    
    foodPos.setObjPos(randX, randY, 'x');
}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.x = foodPos.x;
    returnPos.y = foodPos.y;
}

int Food::getFoodX()
{
    return foodPos.x;
}

int Food::getFoodY()
{
    return foodPos.y;
}

char Food::getFoodSymbol()
{
    return foodPos.symbol;
}