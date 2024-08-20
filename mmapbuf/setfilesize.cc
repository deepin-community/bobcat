#define XERR
#include "mmapbuf.ih"

    // 'mode' defines the access permissions of the file when it's creaed.
    // by default rw-r--r-- (0644) and is passed to MmapBuf via the [IO]mapbuf
    // derived class

void MmapBuf::setFileSize(mode_t mode)
{
//    ios::
//      in      the file must exist
//      out     recreates unless also in
//      ate     start initially at the end. Needs in to prevent rewriting
//      trunc   truncates, with in|out reading also OK
//      app     when writing always reposition to the end

    if (d_openMode & ios::app)
        d_openMode |= ios::out;

    if (                                        // create the file if
        (d_openMode & ios::trunc)               // truncate or
        or                                      // out-mode w/o in-mode
        ((d_openMode & ios::out) and (d_openMode & ios::in) == 0)
    )
    {
        if (creat(d_fname.c_str(), mode) == -1)
            failure("can't create " + d_fname);

        d_fileSize = 0;
        return;
    }
     
    Stat stat{ d_fname };                   // obtain the file's info

    if (not stat)
        failure("can't stat " + d_fname);

    d_fileSize = stat.size();
}
