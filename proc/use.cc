#include "proc.ih"

//  bit == COUT:    if d_mode & MERGE_COUT_CERR, MERGE_COUT_CERR is kept
//  bit == CERR:    if d_mode & MERGE_COUT_CERR, MERGE_COUT_CERR is replaced
//                  by CERR | COUT: COUT keeps its own Out stream, CERR
//                  gets the use-specified stream

Proc::Out &Proc::use(IOMode bit)        // bit to be set in d_mode 
{
    d_mode |= bit;

    switch (bit)
    {
        case COUT:
            if (d_mode & MERGE_COUT_CERR)
                d_mode |= CERR;
//            d_mode  &= ~(MERGE_COUT_CERR | IGNORE_COUT | IGNORE_CERR);
            d_admin |= USE_OUT;
        return d_out;

        case CERR:
            if (d_mode & MERGE_COUT_CERR)
                d_mode |= COUT;
//            d_mode  &= ~(MERGE_COUT_CERR | IGNORE_COUT | IGNORE_CERR);
            d_admin |= USE_ERR;
        return d_err;

        default:    // = case MERGE_COUT_CERR: use is only called with
                    // arguments COUT, CERR or MERGE_COUT_CERR
            d_mode  &= ~(COUT | CERR | IGNORE_COUT | IGNORE_CERR);
            d_admin |= USE_OUT;
        return d_out;
    }
}


