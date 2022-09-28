#include "config.ih"

void CF_Pimpl::load(istream &stream, uint16_t lineNr)
{
    clear();

    d_rawNumber = lineNr - 1;

    string line;
    while (nextLine(stream, line))  // add the lines to d_line
        d_line.push_back({ d_rawNumber, std::move(line) });
}
