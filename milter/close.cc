#include "milter.ih"

sfsistat Milter::close()
{
    smfi_setpriv(d_ctx, 0);         // delete this d_ctx data

    return CONTINUE;
}
