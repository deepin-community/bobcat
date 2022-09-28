inline CSVTabIns &operator<<(CSVTabIns &tab,
                            std::ios_base &(*func)(std::ios_base &))
{
    return tab.insert(func);
}

inline CSVTabIns &operator<<(CSVTabIns &&tab,
                            std::ios_base &(*func)(std::ios_base &))
{
    return tab << func;
}

