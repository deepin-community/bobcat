#include "ofoldbuf.ih"

OFoldBuf::BufIt OFoldBuf::findOFoldBuf(streambuf const *buf)
{
    BufIt it = find(s2_buffers.begin(), s2_buffers.end(),
                dynamic_cast<OFoldBuf const *>(buf));

    if (it == s2_buffers.end())
        throw Exception{1} <<
                "Illegal cast from std::streambuf to FBB::OFoldBuf";

    return it;
}
