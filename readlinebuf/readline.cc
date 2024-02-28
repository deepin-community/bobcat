#include "readlinebuf.ih"

size_t ReadLineBuf::readLine()
{
    ofstream out{"/tmp/log", ios::app};
    out << "called" << endl;

    char *buf = readline(d_prompt.c_str());     // readline(3)

    if (buf == 0)
        return 0;

    return nextLine(buf);
}
