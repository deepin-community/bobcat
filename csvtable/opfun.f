    // insert fields values into d_out
inline void CSVTable::operator()(std::string const &text)
{
    row(text, ~0U);
}
