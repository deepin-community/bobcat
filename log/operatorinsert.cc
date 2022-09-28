#include "log.ih"

namespace FBB
{

std::ostream &operator<<(std::ostream &str, LogManipulator manipulator)
{
    switch (manipulator)
    {
        case FATAL:
            str.flush();
        throw Exception(1);

        case nl:
            str << static_cast<char>(0);    // 0-char is interpreted by
                                            // LogBuf as '\n', without
        break;                              // timestamp writing request.

        case fnl:
            str << static_cast<char>(1);
        break;
    }
    return str;
}
        
} // FBB
