#include "datetime.ih"

    // dst specification:   Mon, wkspec Day [hh:mm]
    // wkspec: 1st, 2nd, 3rd, 4th, 5th, or last

// static
string DateTime::Zone::convert(string const &dstSpec)
{
    vector<string> vs;
    String::split(&vs, dstSpec, String::TOK, ", "); // get the , and space
                                                    // separated elements

    if (vs.size() < 3 || vs.size() > 4)
        throw 1;

    string monthNr = to_string(1 + stdFind(s_month, 12, vs[0]));
                                                        
    char wkSpec =                                       // handle 1st, etc.
            "1234"s.find(vs[1][0]) != string::npos ?    // Otherwise: '5'
                vs[1][0]                                // for last
            :
                '5';

    char dayOffset = '0' + stdFind(s_day, 7, vs[2]);

    return ",M"s + monthNr + '.' + wkSpec + '.' + dayOffset +
            (vs.size() == 4 ? '/' + vs.back() : "");
}
