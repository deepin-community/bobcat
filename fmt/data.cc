//#define XERR
#include "fmt.ih"

char const *FMT::s_align[] =           // follows the Align enum values
{
    "unused",
    "center",
    "hline",
    "left",
    "right",
};

FMT::FMTFun FMT::s_lrcFun[] = 
{
    0, 
    center,
    0, 
    left,
    right,
};

