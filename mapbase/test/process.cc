#include "main.ih"

void process()
{
    while (true)
    {
        map();

        if ((*checkFit)())
        {
            nToDo = 0;
            break;
        }

        size_t nAvail = offset + bufSize - currentPos;
        nToDo -= nAvail;
        cout << "   " << what << ' ' << nAvail << fromTo << 
                                                        currentPos << '\n';
        currentPos = offset + bufSize;

    }
    
    cout << "   next offset at " << currentPos << '\n';
}


//
//        cout << "next [Yn]? ";
//        string line;
//        getline(cin, line);
//        if (not line.length() or line.front() != 'y')
//            break;

