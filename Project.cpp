#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;

objPos playerPos;
objPos* myPlayer;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(getExitFlagStatus() == false)  
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

    myGM = new GameMechs(30 , 15);
    myPlayer = new Player(myGM);
 
}

void GetInput(void)
{

}

void RunLogic(void)
{
    updatePlayerDir();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();  

    for(int i=0; i < mainGameMechsRef->getBoardSizeY(); i++){
        for(int j=0; j < mainGameMechsRef->getBoardSizeX(); j++){
            if(i == playerPos.y && j == playerPos.x)
                MacUILib_printf("%c", playerPos.symbol);
            else if(i==0 || i==mainGameMechsRef->getBoardSizeY()-1 || j==0 || j==mainGameMechsRef->getBoardSizeX()-1)
                MacUILib_printf("%c", '#');
            else    
                MacUILib_printf("%c", ' ');
            
        }
        MacUILib_printf("\n");
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    //~GameMechs();
    delete myGM;
    //~Player();
    delete myPlayer;
}
