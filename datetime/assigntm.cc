#include "datetime.ih"

    // from utc seconds + current zone to TM
    // use utcFromTM to obtain UTC seconds given zone and spec. in TM
struct tm const &DateTime::assignTM() const
{
    setTZ(zone().spec());
    
    if (not localtime_r(&d_utcSec, &d_tm))
        throw Exception{ 1 } << "can't compute time for " <<
                                zone().spec() << '\n';

    resetTZ();

    return d_tm;
}
