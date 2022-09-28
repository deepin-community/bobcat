template <typename Type>
CSVTabDef &CSVTabDef::insert(Type const &value)
{
    std::ostringstream str;
   
    str << value;

    add(str.str());

    return *this;    
}
