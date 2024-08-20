#include "main.ih"

bool writeFit()
{
    if (bufSize < nToDo)               // characters don't fit 
        return false;

    cout << "   fits: writing " << nToDo << " to " << currentPos << '\n';

    currentPos += nToDo;

    if (realSize < currentPos)
        realSize = currentPos;

    return true;
}
    
