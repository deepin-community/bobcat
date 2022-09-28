inline CSVTabIns &operator<<(CSVTabIns &tab, FMT::FMTHline hline)
{
    return tab << (*hline)(1);      // insert hline in the next column
}

inline CSVTabIns &operator<<(CSVTabIns &&tab, FMT::FMTHline hline)
{
    return tab << hline;
}

