inline CSVTabIns &operator<<(CSVTabIns &tab, FMT const &fmt)
{
    return tab.insert(fmt);
}

inline CSVTabIns &operator<<(CSVTabIns &&tab, FMT const &fmt)
{
    return tab << fmt;
}
