#include "ldc.ih"

ostream &LDC::indices(ostream &out) const
{
    return out <<
            "   lsb: " << idx(d_lsb, d_cb) <<
                ", begin: " << idx(d_begin.ptr, d_cb) <<
                ", end: " << idx(d_end, d_cb) << "\n"
           "   divBegin: " << idx(d_divBegin, not d_cb) <<
                ", divEnd: " << idx(d_divEnd, not d_cb);
 }
