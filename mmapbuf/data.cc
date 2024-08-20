#define XERR
#include "mmapbuf.ih"

size_t MmapBuf::s_pageSize = sysconf(_SC_PAGE_SIZE);
