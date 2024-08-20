//inline void MapBase::setPos(size_t pos)
//{
//    d_absPos = pos;
//}
//

inline size_t MapBase::absPos() const
{
    return d_absPos;
}

inline std::string const &MapBase::fname() const
{
    return d_fname;
}

inline std::ios::openmode MapBase::mode() const
{
    return d_mode;
}

inline size_t MapBase::fileSize() const
{
    return d_fileSize;
}

inline size_t MapBase::realSize() const
{
    return d_fileSize;
}

inline size_t MapBase::offset() const
{
    return d_offset;
}

inline size_t MapBase::mapLength() const
{
    return d_mapLength;
}

inline char *MapBase::begin()
{
    return d_cp;
}

inline char *MapBase::next()
{
    return d_cp + d_absPos - d_offset;
}

inline char *MapBase::end()
{
    return d_cp + d_mapLength;
}

inline bool MapBase::append() const
{
    return (d_mode & IOS::app) != 0;
}

