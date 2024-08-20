#include "mapbase.ih"

void MapBase::setBufLength(char const *bufSize)
{
    if (bufSize == 0)
        d_bufferSize = 0;
    else
    {
        string spec{ bufSize };
    
        d_bufferSize = stoul(spec);
        switch (spec.back())                    // extend by K,M,G suffixes
        {
            case 'K':
                d_bufferSize *= 1024;
            break;
    
            case 'M':
                d_bufferSize *= 1024 * 1024;
            break;
    
            case 'G':
                d_bufferSize *= 1024 * 1024 * 1024;
            break;
        }
    }

    if (d_bufferSize < 10 * s_pageSize)        // the buffer is at least 
        d_bufferSize = 10 * s_pageSize;        // 10 * page size

                                        // for reading: bufLength is at
                                        // most equal to the file size
    if (not d_writing and d_bufferSize > d_orgSize)
        d_bufferSize = d_orgSize;             // then use the file size
}




