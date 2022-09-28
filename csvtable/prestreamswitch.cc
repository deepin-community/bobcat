//#define XERR
#include "csvtable.ih"

int CSVTable::preStreamSwitch()
{
    if (d_idx != 0)                 // not at the beginning of a row
        row();                      // then end the current row

    int ret = d_out->fill();        // keep the current fillChar

    streamReset();                  // reset *d_out to its original
                                    // settings
    return ret;
}
