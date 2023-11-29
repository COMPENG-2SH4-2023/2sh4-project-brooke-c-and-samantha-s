#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;

Player* myPlayer;
objPosArrayList* playerPosList;

Food* myFood;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(30, 15);
    myFood = new Food(myGM);

    myPlayer = new Player(myGM, myFood);
}

void GetInput(void)
{

}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 

    bool draw;

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempBody;


    for(int i=0; i < myGM->getBoardSizeY(); i++){
        for(int j=0; j < myGM->getBoardSizeX(); j++){
            draw = false;

            for(int k = 0; k < playerBody->getSize(); k++){
                playerBody->getElement(tempBody, k);
                if(j == tempBody.x && i == tempBody.y){
                    MacUILib_printf("%c", tempBody.symbol);
                    draw = true;
                    break;
                }
            }

            if(draw) continue;

            else if(i == myFood->getFoodY() && j == myFood->getFoodX())
                MacUILib_printf("%c", myFood->getFoodSymbol());
            else if(i==0 || i==myGM->getBoardSizeY()-1 || j==0 || j==myGM->getBoardSizeX()-1)
                MacUILib_printf("%c", '#');
            else    
                MacUILib_printf("%c", ' ');
        }
        MacUILib_printf("\n");
    }

    MacUILib_printf("Score: %d", myGM->getScore());
}
 
void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    myGM->~GameMechs();
    myPlayer->~Player();
    delete myFood;
}
