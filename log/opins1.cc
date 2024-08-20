#include "log.ih"

ostream &operator<<(ostream &str, FBB::LogManipulator manip)
{
    if (FBB::Log *ptr = dynamic_cast<Log *>(&str); ptr != 0)
        *ptr << manip;

    return str;
}



