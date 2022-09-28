#include "osharedstream.ih"

void OSharedStream::memInfo(std::ostream &out, char const *end) const
{
    static_cast<SharedBuf const *>(this)->memInfo(out);
    out << end;
}
