#include "proc.ih"

void Proc::rmBackticks()
{
    if (d_cmd.front() == '`' && d_cmd.back() == '`')  // rm backticks
    {
        d_cmd.resize(d_cmd.length() - 1);   // rm last backtick
        d_cmd.erase(0, 1);                      // rm front backtick
    }

}
