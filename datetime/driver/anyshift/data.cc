#include "main.ih"

bool setHours = false;
bool showDesired = false;

int hours;

time_t desiredDST;       // desired DST info (all in seconds)
time_t desiredZone;      // desired zone shift, not considering DST
time_t thisDST;
time_t thisZone;
