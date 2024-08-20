#define XERR
#include "mapbase.ih"

bool MapBase::map(int protection)   // PROT_READ, PROT_WRITE or both
{
    if (not d_writing and d_absPos >= d_orgSize)   // nothing to map at EOF
        return false;                               // when reading

    unmap();

// WIP:
    if (not d_absolute)
        d_absPos = d_offset + pptr() - pbase();

    d_offset = d_absPos  / s_pageSize * s_pageSize; // d_offset <= d_absPos

    if (d_writing)
        writingMapLength();
    else if (not readingMapLength())    // set the reading mapLength
        return true;                    // no length: don't mmap


//xerr("absPos = " << d_absPos << ", offset " << d_offset <<\X=========
//", length: " << d_mapLength << ", enlarged size: " << d_enlargedSize);


    int fd = open(d_fname.c_str(), 
                  protection == PROT_READ  ? O_RDONLY : O_RDWR);

    if (fd == -1)                               // file can't be opened
        throw Exception{} << "can't open " << d_fname;

        // d_mapLength may exceed the file's size
    d_cp = static_cast<char *>(                 // mmap the required buffer
                mmap(0, d_mapLength, protection, MAP_SHARED, fd, d_offset)
            );

    close(fd);

    if (d_cp == MAP_FAILED)                     // mapping failed
        throw Exception{} << "mmap for " << d_fname << " failed";

    d_mMapped = true;

    // no set{pg} because they're called by {io}mapbuf

    return true;
}

