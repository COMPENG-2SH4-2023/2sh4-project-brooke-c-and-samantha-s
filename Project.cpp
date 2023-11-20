#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;
//bool exitFlag;

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

    while(exitFlag == false)  
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
    myPlayer->updatePlayerDir();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();  

    for(i=0; i < getBoardSizeY(); i++){
        for(j=0; j < getBoardSizeX(); j++){
            if(i == playerPos.y && j == playerPos.x)
                MacUILib_printf("%c", playerPos.symbol);
            else if(i==0 || i==getBoardSizeY()-1 || j==0 || j==getBoardSizeX()-1)
                MacUILib_printf("%c", '#');
            else    
                MacUILib_printf("%c", ' ');
            
        }
        MacUILib_printf("\n");
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
}
