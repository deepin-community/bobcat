#include "sharedstream.ih"

void SharedStream::memInfo(std::ostream &out, char const *end) const
{
    static_cast<SharedBuf const *>(this)->memInfo(out);
    out << end;
}

