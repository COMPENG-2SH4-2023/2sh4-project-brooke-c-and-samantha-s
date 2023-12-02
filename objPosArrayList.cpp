#include "objPosArrayList.h"

// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    sizeList = 0;
    sizeArray = ARRAY_MAX_CAP;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    // if(sizeList == sizeArray){
    //     cout << "Cannot insert, list is FULL." << endl;
    //     return;
    // }

    for(int i = sizeList; i > 0; i--)
        aList[i] = aList[i-1];

    aList[0] = thisPos;
    sizeList++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    // if(sizeList == sizeArray){
    //     cout << "Cannot insert, list is FULL." << endl;
    //     return;
    // }

    aList[sizeList++] = thisPos;
}

void objPosArrayList::removeHead()
{
    // if(sizeList == sizeArray){
    //     cout << "Cannot remove, list is EMPTY." << endl;
    //     return;
    // }

    for(int i = 0; i < sizeList - 1; i++)
        aList[i] = aList[i+1];

    sizeList--;
}

void objPosArrayList::removeTail()
{
    // if(sizeList == sizeArray){
    //     cout << "Cannot remove, list is EMPTY." << endl;
    //     return;
    // }

    sizeList--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    // if(sizeList == sizeArray){
    //     cout << "Cannot get element, list is EMPTY." << endl;
    //     return;
    // }
    
    returnPos = aList[0];
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    // if(sizeList == sizeArray){
    //     cout << "Cannot get element, list is EMPTY." << endl;
    //     return;
    // }

    returnPos = aList[sizeList-1];
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    // if(sizeList == 0 || index < 0 | index >= sizeList){
    //     cout << "Cannot retreive element, index out of bounds."
    //     return;
    // }

    returnPos = aList[index];
}