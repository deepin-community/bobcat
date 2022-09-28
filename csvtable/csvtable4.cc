//#define XERR

#include "csvtable.ih"

CSVTable::CSVTable(CSVTable &&tmp)
:
    d_format   (move(tmp.d_format)),

    d_strPtr   (move(tmp.d_strPtr)),
    d_out      (tmp.d_out),
    d_sep      (move(tmp.d_sep)),

    d_flags    (tmp.d_flags),               // original stream flags
    d_precision(tmp.d_precision),
    d_fillChar(tmp.d_fillChar),

    d_idx      (tmp.d_idx)
{
    tmp.d_idx = 0;
    tmp.d_out = &cout;                      // moving associates tmp with cout
    tmp.streamFlags();
}
