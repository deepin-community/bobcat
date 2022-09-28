inline size_t ConfigFile_::index(const_iterator const &iterator)
{
    return d_index[iterator - begin()];
}
