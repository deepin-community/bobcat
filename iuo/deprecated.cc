#include "iuo.ih"

namespace FBB
{
    void deprecated__(bool &called, char const *msg)
    {
        if (called)
            return;
    
        cerr << "\n[Warning] " << msg << 
            " is deprecated.\n"
            "Avoid its use, see the man-page for alternatives.\n";
        called = true;
    }
}

