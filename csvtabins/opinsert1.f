template <typename Type>
inline CSVTabIns &operator<<(CSVTabIns &tab, Type const &value)
{
    return tab.insert(value);
}

        // this one is called from CSVTable::operator CSVTabIns():
        //
template <typename Type>
inline CSVTabIns &operator<<(CSVTabIns &&tab, Type const &value)
{
    return tab << value;
}


