#include "digestbuf.ih"

namespace FBB
{

std::ostream &operator<<(std::ostream &out, DigestBuf const &digestbuf)
{
    OHexBuf ohex(out);
    ostream outs(&ohex);
    outs.write(digestbuf.d_digest.data(), digestbuf.d_digest.length());
    return out;
}

} // FBB
