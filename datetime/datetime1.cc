#include "datetime.ih"

// UTC time = ::time(0)
DateTime::DateTime(TimeType type)
:
    DateTime(::time(0), type)           // 6.cc
{}
