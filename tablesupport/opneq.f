inline bool FBB::TableSupport::const_iterator::operator!=(
    FBB::TableSupport::const_iterator const &other) const
{
    return not (*this == other);
}
