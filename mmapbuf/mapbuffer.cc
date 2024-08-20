#define XERR
#include "mmapbuf.ih"

void MmapBuf::mapBuffer(int protection)
{
    int fd = open(d_fname.c_str(), 
                  protection == PROT_READ  ? O_RDONLY : O_RDWR
    );

    if (fd == -1)                               // file can't be opened
        failure("can't open " + d_fname);

        // mmap and munmap accept buffers for reading exceeding the file size
    d_buffer = static_cast<char *>(             // mmap the required buffer
                    mmap(0, d_bufSize, protection, MAP_SHARED, fd, d_offset)
                );

    close(fd);

    if (d_buffer == MAP_FAILED)                 // mapping failed
        failure("mmap for " + d_fname + " failed");

    d_maxPtr = d_buffer;
}

