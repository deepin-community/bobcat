#include "datetime.ih"

// static
void DateTime::Zone::read(std::string const &fname)
{
    ifstream in = Exception::factory<ifstream>(fname);  // open the file

    unsigned lineNr = 0;
    string line;

    while (getline(in, line))
    {
        ++lineNr;

        line = String::trim(line);
        if (line.empty() || line[0] == '#')
            continue;

        addZone(line, fname, lineNr);
    }
}
