#include "readlinebuf.ih"

ReadLineBuf::~ReadLineBuf()
{
    if (d_history)
        clear_history();
}
