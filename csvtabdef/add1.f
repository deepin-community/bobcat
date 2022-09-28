inline void CSVTabDef::add(std::string const &field)
{
    add(String::trim(field).length());
}
