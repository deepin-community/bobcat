#include "log.ih"

namespace FBB
{
    Log &operator<<(Log &log, LogManipulator manip)
    {
        if (
            bool opfunOK = log.d_active->opfunOK;
            opfunOK || log.d_active->levelOK
        )
        {
            switch (manip)
            {
                case FATAL:
                    log.flush();
                throw Exception{1} << "LogManipulator::FATAL";
        
                case nl:                            // 0-char is interpreted by
                    log << static_cast<char>(0);    // LogBuf as '\n', without
                break;                              // writing a timestamp
       
                case fnl:
                    log << static_cast<char>(1);
                break;
            }

            if (opfunOK and manip != nl)
                log.d_active->opfunOK = false;
        }

        return log;
    }
}




