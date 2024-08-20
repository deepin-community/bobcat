inline size_t FBB::ConfigFile_::index(const_iterator const &iterator)
{
    return d_index[iterator - begin()];
}
