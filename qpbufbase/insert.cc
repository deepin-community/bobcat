#include "qpbufbase.ih"

void QPBufBase::insert(int ch)
{
    if (isprint(ch) && ch != '=')
        d_pending += ch;
    else
        escape(ch);
}
