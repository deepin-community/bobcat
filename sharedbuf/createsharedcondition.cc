#include "sharedbuf.ih"

SharedCondition SharedBuf::createSharedCondition()
{
    auto sharedCondition(SharedCondition::create(d_memory));
    seekoff(sharedCondition.offset() + sharedCondition.size());
    return sharedCondition;
}
