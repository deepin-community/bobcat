#include "signal.ih"

unique_ptr<Signal> Signal::s_signal;

Signal &Signal::instance()
{
    if (s_signal == 0)
        s_signal.reset(new Signal);

    return *s_signal;
}
