inline bool LogBuf::empty() const
{
    return d_empty;
}

inline void LogBuf::setActive(bool active)
{
    if (d_active != OFF)
        d_active = active ? ACTIVE : NOT_ACTIVE;
}

inline void LogBuf::setActive(Active active)
{
    d_active = active;
}

inline bool LogBuf::active() const
{
    return d_active == ACTIVE;
}

inline void LogBuf::setEmpty(bool empty)
{
    d_empty = empty;
}

inline void LogBuf::setStream(std::ostream &stream)
{
    d_stream = &stream;
}
