#include "Player.h"
#include "GameMechs.h"
#include "objPos.h"
#include <iostream>
#include "Food.h"
#include "objPosArrayList.h"


Player::Player(GameMechs* thisGMRef, Food* foodRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    headPos.setObjPos(15, 7, '@');
    // more actions to be included
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(headPos);

    food = foodRef;
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}
 
objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos array list
    return playerPosList;
}

int Player::getPlayerX()
{
    return headPos.x;
}

int Player::getPlayerY()
{
    return headPos.y;
}

char Player::getPlayerS()
{
    return headPos.symbol;
}

bool Player::checkSelfCollision()
{
    objPos currHead;
    playerPosList->getHeadElement(currHead);

    for(int i = 1; i < playerPosList->getSize(); i++)
    {
        playerPosList->getElement(headPos, i);
        if(currHead.x == headPos.x && currHead.y == headPos.y)
            return true;
    }
    return false;
}

bool Player::checkFoodConsumption()
{
    objPos currHead;
    playerPosList->getHeadElement(currHead);

    if(currHead.x == food->getFoodX() && currHead.y == food->getFoodY())
        return true;
    return false;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic  
    char input = mainGameMechsRef->getInput();

    switch(input)
    {
        case 'a':
            if(myDir != RIGHT)
                myDir = LEFT;
            break;
        case 'w':
            if(myDir != DOWN)
                myDir = UP;
            break;
        case 'd':
            if(myDir != LEFT)
                myDir = RIGHT;
            break;
        case 's':
            if(myDir != UP)
                myDir = DOWN;
            break;  
        case ' ':
            mainGameMechsRef->setExitTrue();
            break;
        default:
            break;
    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    objPos currHead;
    playerPosList->getHeadElement(currHead);

    switch(myDir){
        case LEFT: 
            currHead.x--;
            if(currHead.x < 1)
                currHead.x = mainGameMechsRef->getBoardSizeX() - 2;

            break;

        case RIGHT:
            currHead.x++;
            if(currHead.x > mainGameMechsRef->getBoardSizeX() - 2)
                currHead.x = 1;

            break;
            
        case UP:
            currHead.y--;
            if(currHead.y < 1)
                currHead.y = mainGameMechsRef->getBoardSizeY() - 2;

            break;

        case DOWN:
            currHead.y++;
            if(currHead.y > mainGameMechsRef->getBoardSizeY() - 2)
                currHead.y = 1;

            break;
    }

    if(checkSelfCollision())
    {
        mainGameMechsRef->setExitTrue();
        mainGameMechsRef->setLoseTrue();
    }
    if(checkFoodConsumption()){
        playerPosList->insertHead(currHead);
        food->generateFood(playerPosList);
        mainGameMechsRef->incrementScore();
    }
    
    // new current head should be inserted to head of list, then remove tail
    
    else{
        playerPosList->insertHead(currHead);
        playerPosList->removeTail();
    }
}