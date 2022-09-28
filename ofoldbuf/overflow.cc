#include "ofoldbuf.ih"

int OFoldBuf::overflow(int ch)
{
    //cerr << c << ' ' << static_cast<char>(ch) << endl;

    switch (d_mode)
    {
        case INDENT: 
            indent(ch);
        break;

        case WS:
            ws(ch);
        break;

        case NON_WS:
            nonWs(ch);
        break;
    }

    return ch;
}
