inline std::ostream &operator<<(std::ostream &str, FBB::TableBase &table)
{
    return table.insert(str);
}
