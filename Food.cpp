#include "Food.h"
#include "GameMechs.h"
#include "objPos.h"

Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    foodPos.setObjPos(2, 2, 'o');
}

Food::~Food()
{
    //delete Food;
}

void Food::generateFood(objPosArrayList* blockOff) // needs to be changed
{
    objPos element;

    randX = (rand() % mainGameMechsRef->getBoardSizeX())+1; // generates random positions
    randY = (rand() % mainGameMechsRef->getBoardSizeY())+1;
    
    for(int i = 0; i < blockOff->getSize(); i++){
        
        blockOff->getElement(element, i);

        if(randX == element.x && randY == element.y){
            randX = (rand() % mainGameMechsRef->getBoardSizeX())+1; 
            randY = (rand() % mainGameMechsRef->getBoardSizeY())+1;
            i--;
        }
    }
    
    
    foodPos.setObjPos(randX, randY, 'o');
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