#include "main.ih"

void setRead()
{
    if (currentPos + nToDo > fileSize)
    {
        size_t nAvail = fileSize - currentPos;
        if (nAvail == 0)
        {
            cout << "at EOF: can't read " << nToDo << " bytes\n";
            throw false;
        }

        cout << "available till EOF: " << nAvail << 
                ": reducing N to read to " << nAvail << '\n';

        nToDo = nAvail;
    }
}

