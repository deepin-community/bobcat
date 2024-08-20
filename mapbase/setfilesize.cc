#define XERR
#include "mapbase.ih"

void MapBase::setFileSize(mode_t mode)
try
{
//    ios::
//      in      the file must exist
//      out     recreates unless also in
//      ate     start initially at the end. Needs in to prevent rewriting
//      trunc   truncates, with in|out reading also OK
//      app     when writing always reposition to the end

    if (d_mode & ios::app)
        d_mode |= ios::out;

    if (
        (d_mode & ios::trunc)               // truncate or
        or                                  // out-mode w/o in-mode
        ((d_mode & ios::out) and (d_mode & ios::in) == 0)
    )
    {
        if (creat(d_fname.c_str(), mode) == -1)
            throw -1;

        d_orgSize = 0;
        return;
    }
     
    Stat stat{ d_fname };                   // obtain the file's info

    if (not stat)
        throw -1;

    d_orgSize = stat.size();
}
catch (...)
{
    throw Exception{} << "can't open " << d_fname;
}
