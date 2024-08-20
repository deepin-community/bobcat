//                     usage.cc

#include "main.ih"

namespace {
char const info[] = R"_( [options] arg
Where:
    [options] - optional arguments (short options between parentheses):
        --help (-h)         - provide this help
        --version (-v)      - show version information and terminate
    
    arg:
        curves: show the available elliptic curves on cout
        init:   compute the initiator's public/secret keys writing them to
                init.pub and init.sec
        peer:   compute the peer's public/secret keys writing them to
                peer.pub and peer.sec, compute the peer's shared key
                (peer.shared)
        priv:   compute the initiator's shared key (init.shared) after making
                peer.pub available in a separate process, using a single
                initiator process.
        shared: compute the initiator's shared key (init.shared) using a
                separate initiator process

)_";

}

void usage(std::string const &progname)
{
    cout << "\n"
    "Usage: " << progname << info;
}
