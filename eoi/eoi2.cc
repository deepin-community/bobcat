#include "eoi.ih"

namespace FBB
{
    std::ostream &eoi(std::ostream &out)
    {
        Eoi *buf = dynamic_cast<Eoi *>(out.rdbuf());
    
        if (buf != 0)
            buf->eoi_();            // call the appropriate 
    
        return out;
    }
}
