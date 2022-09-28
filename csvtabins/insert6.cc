//#define XERR
#include "csvtabins.ih"

    // insert manipulators like left and right
CSVTabIns &CSVTabIns::insert(ios_base &(*func)(ios_base &))
{
    if (
        FMT::Align align = func == std::left  ? FMT::LEFT  :
                           func == std::right ? FMT::RIGHT :
                                                FMT::UNUSED;
        
        align == FMT::UNUSED 
    )                           // manipulators other than left/right
        *d_out << func;         // are directly inserted
    else
        *this << align;  // or handle LEFT and RIGHT

    return *this;
}

