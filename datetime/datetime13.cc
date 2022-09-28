#include "datetime.ih"

DateTime::DateTime(istream &in, TimeType type)
:
    d_type(type)
{
    Parse parse{ in, d_tm };

    Zone zone{ Zone::get("<000>") };        // get the UTC zone

    string zoneName;

    switch (parse.format())
    {
        case 1:                 // Mon Dec 3 13:29:11 2018
            zoneName =  d_type == LOCALTIME ? "<001>" : "<000>";
        break;

        case 2:
            zoneName = parse.zoneName();
        break;
            
        case 3:                 // Mon, 3 Dec 2018 13:29:11 +0100
        case 4:                 // 2018-12-03 13:29:11+01:00
            if (type == UTC)
            {
                d_tm.tm_sec -= parse.zoneSeconds();    // UTC spec in d_tm
                zoneName = "<000>";
            }
        break;
    }

    d_zone = zoneName.empty() ?
                    Zone{ seconds2str(parse.zoneSeconds()) }
                :
                    Zone::get(zoneName);

    d_utcSec = utcFromTM(d_tm);
    assignTM();
}



