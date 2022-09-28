inline void SyslogStream::open(std::string const &ident, Priority priority, 
                               Facility facility, int option)
{
    reset(ident, priority, facility, option);
}
