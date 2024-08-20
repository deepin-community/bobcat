#define XERR
#include "mmapbuf.ih"

void MmapBuf::setBufSize(char const *bufSize)
{
    if (bufSize == 0)
    {
        d_bufSize = 10 * s_pageSize;
        return;
    }

    string spec{ bufSize };

    d_bufSize = stoul(spec);

    switch (spec.back())                    // extend by K,M,G suffixes
    {
        case 'K':
            d_bufSize *= 1024;
        break;

        case 'M':
            d_bufSize *= 1024 * 1024;
        break;

        case 'G':
            d_bufSize *= 1024 * 1024 * 1024;
        break;
    }
                                            // at least s_pageSize
    d_bufSize = max(s_pageSize, d_bufSize / s_pageSize * s_pageSize);
}




