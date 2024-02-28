#include "log.ih"

namespace FBB
{
    Log &operator<<(Log &log, ostream &(*fun)(ostream &))
    {
        if (log.d_active->opfunOK)
        {
            static_cast<std::ostream &>(log) << fun;

            if (static_cast<ostream &(*)(ostream &)>(&std::endl) == fun)
                log.d_active->opfunOK = false;
        }
        return log;
    }
}


