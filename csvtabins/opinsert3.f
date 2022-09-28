inline CSVTabIns &operator<<(CSVTabIns &tab, FMT::Align align)
{
    return tab.insert(align);
}

inline CSVTabIns &operator<<(CSVTabIns &&tab, FMT::Align align)
{
    return tab << align;
}

