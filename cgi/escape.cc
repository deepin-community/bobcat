#include "cgi.ih"

string CGI::escape(string const &text)
{
    string ret;

    auto begin = text.begin();
    auto end = text.end();

    while (true)
    {
        auto mid = find_if(begin, end,
            [&](unsigned char ch)
            {
                return d_escape[ch];
            }
        );

        ret.append(begin, mid);

        if (mid == end)
            break;

        ret += '\\';
        ret += *mid;
        begin = mid + 1;
    }

    return ret;
}

//    string ret = text;
//
//    for (size_t idx = ret.length(); idx--; )
//    {
//        if (d_escape[static_cast<unsigned char>(ret[idx])])
//            ret.insert(idx, "\\");
//    }
//    return ret;
//}
