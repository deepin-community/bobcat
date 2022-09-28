#include "sharedstream.ih"

SharedStream::SharedStream(int id, std::ios::openmode openMode)
:
    SharedBuf(id, openMode),
    std::istream(this),
    std::ostream(this)
{}
