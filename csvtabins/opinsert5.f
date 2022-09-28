inline CSVTabIns &operator<<(CSVTabIns &tab, Sep const &sep)
{
    return tab.sep(sep);
}

inline CSVTabIns &operator<<(CSVTabIns &&tab, Sep const &sep)
{
    return tab << sep;
}

