#include "main.ih"

void setWrite()      // writing
{
    if (currentPos + nToDo > fileSize)
    {
        fileSize = (currentPos + nToDo + bufSize) / bufSize * bufSize;
        cout << "\nnew file size: " << fileSize << '\n';
    }
}


