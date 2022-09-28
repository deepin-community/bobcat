#include "datetime.ih"

DateTime::Zone::Zone(string const &spec)
{
    switch (spec[0])
    {
        case ':':                   // E.g., :Asia/Calcutta. Maybe DST is
                                    // never used, but then tm_isdst remains 0
            d_data = { spec, zoneSeconds(spec), 3600 };    
        break;

        case '+':                   // +/-hh::mm zone specification
        case '-':
        case '0'...'9':
            d_data = data(s_anon, spec);
        break;

        default:                    // must be a zone, stored by name
            requireAlpha(spec);
            d_data = get(spec).d_data;
        break;
    }
}
