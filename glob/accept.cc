#include "glob.ih"

void Glob::accept()
{
    auto begin = d_share->begin = new char *[d_share->globStruct.gl_pathc];
    auto dest = begin;

    auto gsTypeEnd = d_share->gsType.end();

    for 
    (
        auto src = d_share->globStruct.gl_pathv, 
             end = src + d_share->globStruct.gl_pathc;
            src != end;
                ++src
    )
    {
        if (d_share->gsType.find( 
                static_cast<Type>(Stat(Stat::LStat, *src).type() & ANY)) 
                     != gsTypeEnd
        )
            *dest++ = *src;             // copy the pointer if type is OK
    }

    d_share->size = dest - begin;       // compute the # of accepted entries
    d_share->end = dest;                // end points beyond the last one
}
