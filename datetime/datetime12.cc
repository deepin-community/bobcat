#include "datetime.ih"

DateTime::DateTime(string const &timeStr,  TimeType type)
:
    DateTime(istringstream{timeStr}, type)                  // 14.f
{}
