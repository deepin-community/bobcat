#include "main.ih"

bool readFit()
{
    if (offset + bufSize < currentPos + nToDo)      // characters don't fit 
        return false;

    cout << "   fits: reading " << nToDo << " from " << currentPos << '\n';
    currentPos += nToDo;

    return true;
}

