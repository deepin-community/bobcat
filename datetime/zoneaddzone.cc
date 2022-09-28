#include "datetime.ih"

// formats:
//   name shift
//   name shift =
//   name shift dstshift
//   name shift dstshift mon, wkspec day until mon, wkspec day
//   name shift dstshift mon, wkspec day until mon, wkspec day [hh:mm] 
//   name shift dstshift mon, wkspec day [hh:mm] until mon, wkspec day
//   name shift dstshift mon, wkspec day [hh:mm] until mon, wkspec day [hh:mm] 

//   dstShift may be =, meaning "1"     (standard dst shift)

void DateTime::Zone::addZone(string const &line, 
                              string const &fname, unsigned lineNr)
try
{
    vector<string> vs;
    String::split(&vs, line, String::TOK, ", ");    // get the : , and space
                                                    // separated elements

    if (vs.size() < 2)          // name and shift not specified
        throw 1;

    if (vs[0].back() == ':')
        vs[0].pop_back();

                                // check whether the zone name is redefined
    s_mutex.lock();
    bool redefining = s_zone->find(vs[0]) != s_zone->end();
    s_mutex.unlock();

    auto [dstBegin, dstEnd] = dstFromVector(vs);

    if (vs.size() == 2)         // need a vs[2], maybe empty.
        vs.resize(3);


    store(vs[0], vs[1], vs[2], dstBegin, dstEnd);
    
    if (redefining)
        cerr << "Warning: " << fname << " line " << lineNr <<
            ": redefining zone `" << vs[0] << "'\n";
}
catch (...)
{
    cerr << fname << " line " << lineNr <<
            ": format error in line `" << line << "'\n";    
}


