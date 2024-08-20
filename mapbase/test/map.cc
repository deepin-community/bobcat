#include "main.ih"

void map()
{
    offset = currentPos / bufSize * bufSize;
    cout << "map: at offset " << offset << ": " << bufSize << " bytes\n";
}

