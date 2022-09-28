#include "config.ih"

bool CF_Pimpl::nextLine(istream &inStream, string &dest)
{
    dest.erase();
    string line;

    while (getline(inStream, line))
    {
        ++d_rawNumber;                               // at the next line

        trimLeft(line);

        bool appendNext = rmCommentAndEscapes(line);

        trimRight(line, appendNext);

        dest += line;
        if (not appendNext)
            return true;
    }

    return dest.length();
}

