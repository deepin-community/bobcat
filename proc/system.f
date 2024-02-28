inline void Proc::system(IOMode mode, size_t bufSize)
{
    system(0, mode, bufSize);
}

inline void Proc::system(size_t timeLimit, IOMode mode, size_t bufSize)
{
    start(timeLimit, mode, USE_SHELL, bufSize);
}
