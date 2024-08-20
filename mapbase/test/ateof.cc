#include "main.ih"

//bool 
void atEOF()
{
    if (not read or currentPos < fileSize)
        return;// false;

    cout << "seekg beyond EOF\n";
//    return true;
}

