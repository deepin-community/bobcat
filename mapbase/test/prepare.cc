#include "main.ih"

void prepare(int argc, char **argv)
{
    if (argc == 2 and *argv[1] == 'r')      // reading
    {
        read = true;
        what = "read";
        seek = "seekg";
        file = nop;
        eofCheck = atEOF;
        setRW = setRead;
        fromTo = " from ";
        checkFit = readFit;
    }
    else
    {
        what = "write";
        seek = "seekp";
        file = setWrite;
//        eofCheck = boolNop;
        eofCheck = nop;
        setRW = setWrite;
        fromTo = " to ";
        checkFit = writeFit;
    }
}
