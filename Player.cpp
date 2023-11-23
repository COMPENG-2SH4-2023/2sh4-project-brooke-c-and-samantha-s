#include "Player.h"
#include "GameMechs.h"
#include "objPos.h"
#include <iostream>


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(15, 7, '*');
}


Player::~Player()
{
    // delete any heap members here
    //delete Player;
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos array list
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
}


void Player::updatePlayerDir()
{
    // PPA3 input processing logic  
    char input = mainGameMechsRef->getInput();

    cout << input << endl;

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
        default:
            break;
    }
    cout << myDir << endl;
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    switch(myDir){
        case 2: 
            playerPos.x--;
            if(playerPos.x < 1)
                playerPos.x = mainGameMechsRef->getBoardSizeX() - 2;

            break;

        case 3:
            playerPos.x++;
            if(playerPos.x > mainGameMechsRef->getBoardSizeX() - 2)
                playerPos.x = 1;

            break;
            
        case 0:
            playerPos.y--;
            if(playerPos.y < 1)
                playerPos.y = mainGameMechsRef->getBoardSizeY() - 2;

            break;

        case 1:
            playerPos.y++;
            if(playerPos.y > mainGameMechsRef->getBoardSizeY() - 2)
                playerPos.y = 1;

            break;
    }
}