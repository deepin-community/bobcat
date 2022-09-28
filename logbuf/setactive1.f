inline void LogBuf::setActive(bool active)
{
    if (d_active != OFF)
        d_active = active ? ACTIVE : NOT_ACTIVE;
}
