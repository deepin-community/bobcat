inline
FBB::TableSupport::const_iterator &FBB::TableSupport::const_iterator::operator++()
{
    ++d_iter;
    return *this;
}
