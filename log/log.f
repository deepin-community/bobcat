inline size_t Log::level() const
{
    return d_level;
}

inline void  Log::off()
{
    setActive(OFF);
}

inline void Log::str(std::string const &accept)
{
    d_active->accept = accept;
}

inline std::string const &Log::str() const
{
    return d_active->accept;
}

template<typename Type>
Log &operator<<(Log &log, Type const &type)
{
    if (log.d_active->levelOK or log.d_active->opfunOK)
        reinterpret_cast<std::ostream &>(log) << type;

    return log;
}

inline Log &operator<<(Log &str, level lvl)
{
    dynamic_cast<std::ostream &>(str) << lvl;
    return str;
}

