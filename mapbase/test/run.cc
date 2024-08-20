#include "main.ih"

void run()
{
    if (not read)
        realSize = fileSize;

    while (get(currentPos, seek))
    {
        (*eofCheck)();                  // for reading, no further action

        try
        {
            while (get(nToDo, "nToDo"))
            {
                (*setRW)();             // setRead or setWrite
                process();
            }
        }
        catch (...)
        {
            break;
        }
//        cout << "mmap buffer from " << offset << " to " << 
//                (offset + bufSize) << '\n';
    }
}


