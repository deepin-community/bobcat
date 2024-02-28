#include "readlinehistory.ih"

ReadLineHistory::~ReadLineHistory()
{
    delete[] d_elements;
}
