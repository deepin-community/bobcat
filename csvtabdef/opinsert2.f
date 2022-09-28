inline CSVTabDef &operator<<(CSVTabDef &tab, FMT const &fmt)
{
    return tab.insert(fmt);
}

inline CSVTabDef &operator<<(CSVTabDef &&tab, FMT const &fmt)
{
    return tab << fmt;
}
