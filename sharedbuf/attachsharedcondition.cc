#include "sharedbuf.ih"

SharedCondition SharedBuf::attachSharedCondition(
                                        std::ios::off_type offset,
                                        std::ios::seekdir way)
{
    auto sharedCondition(SharedCondition::attach(d_memory, offset, way));
    seekoff(sharedCondition.offset() + sharedCondition.size());
    return sharedCondition;
}
