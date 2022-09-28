#include "base64bufbase.ih"

size_t Base64BufBase::indexOf(int ch)
{
    size_t ret = s_tabStr.find(ch);

    if (ret == string::npos)
        throw Exception{} << "Input file not base64 encoded";

    return ret;
}
