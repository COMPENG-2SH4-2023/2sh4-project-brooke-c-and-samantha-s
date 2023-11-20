#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(getBoardSizeX()/2, getBoardSizeY()/2, '@');
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos array list
    returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic  
    char input = getInput();

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
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic

    switch(myDir){
        case LEFT: 
            playerPos.x--;
            if(playerPos.x < 1)
                playerPos.x = getBoardSizeX() - 2;

            break;

        case RIGHT:
            playerPos.x++;
            if(playerPos.x > getBoardSizeX() - 2)
                playerPos.x = 1;

            break;
            
        case UP:
            playerPos.y--;
            if(playerPos.y < 1)
                playerPos.y = getBoardSizeY() - 2;

            break;

        case DOWN:
            playerPos.y++;
            if(playerPos.y > getBoardSizeY() - 2)
                playerPos.y = 1;

            break;
    }
}

