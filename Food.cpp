#include "Food.h"
#include "GameMechs.h"
#include "objPos.h"
#include <stdio.h>

#define FOOD_SIZE 5

Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    //foodPos.setObjPos(2, 2, 'o');

    foodBucket = new objPosArrayList();
}

Food::~Food()
{
    //delete Food;
    delete foodBucket;
}

void Food::generateFood(objPosArrayList* blockOff) // needs to be changed
{
    objPos element, setPos;
    foodBucket->clearList();

    for(int l = 0; l < FOOD_SIZE; l++){
        randX = (rand() % (mainGameMechsRef->getBoardSizeX()-2))+1; // generates random positions
        randY = (rand() % (mainGameMechsRef->getBoardSizeY()-2))+1;
        
        for(int i = 0; i < blockOff->getSize(); i++){
            
            blockOff->getElement(element, i);

            if(randX == element.x && randY == element.y){
                randX = (rand() % (mainGameMechsRef->getBoardSizeX()-2))+1; 
                randY = (rand() % (mainGameMechsRef->getBoardSizeY()-2))+1;
                i--;
            }
        }
        for(int j = 0; j < l; j++){
            foodBucket->getElement(element, j);

            if(randX == element.x && randY == element.y){
                randX = (rand() % (mainGameMechsRef->getBoardSizeX()-2))+1; 
                randY = (rand() % (mainGameMechsRef->getBoardSizeY()-2))+1;
                j--;
            }
        }
        setPos.x = randX;
        setPos.y = randY;
        if(l < 3)
            setPos.symbol = 'o';
        else if(l == 3)
            setPos.symbol = '+';
        else    
            setPos.symbol = '-';

        foodBucket->insertTail(setPos);
    }
}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.x = foodPos.x;
    returnPos.y = foodPos.y;
}

objPosArrayList* Food::getFoodList()
{
    return foodBucket;
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