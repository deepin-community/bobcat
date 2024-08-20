inline FBB::TableSupport::const_iterator FBB::TableSupport::begin(size_t row) const
{
    const_iterator ret(*this, row, true);
    return ret;
}
