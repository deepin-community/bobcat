#include "datetime.ih"

// static
void DateTime::timeException()
{
    throw Exception{ 1 } << "error in time specification";
}
