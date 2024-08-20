#include "log.ih"

void Log::init()
{
    d_active.reset(new Active{ false, false });
    // d_msgLevel = ~0U;

    setLevel(0);
}
