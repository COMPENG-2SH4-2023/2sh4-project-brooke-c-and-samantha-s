#include "Food.h"
#include "GameMechs.h"
#include "objPos.h"

Food::Food()
{
    foodPos.setObjPos(randX, randY, 'x');

}

Food::~Food()
{

}

void Food::generateFood(objPos blockOff)
{
    do{
        randX = (rand() % FoodMech.getBoardSizeX())+1; // generates random positions
        randY = (rand() % FoodMech.getBoardSizeY())+1;
    }while(randX == blockOff.x && randY == blockOff.y);
    
    
}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos.x = this.x;
    returnPos.y = this.y;

}