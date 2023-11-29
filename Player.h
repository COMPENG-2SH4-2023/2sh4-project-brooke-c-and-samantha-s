#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state
        
        Player(GameMechs* thisGMRef, Food* foodRef);
        ~Player();

        objPosArrayList* getPlayerPos(); // Upgrade this in iteration 3.

        // added functions
        int getPlayerX();
        int getPlayerY();
        char getPlayerS();
        
        void updatePlayerDir();
        void movePlayer();

    private:
        objPos headPos;   // Upgrade this in iteration 3.       
        enum Dir myDir;
        objPosArrayList* playerPosList;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;

        Food* food;
};

#endif