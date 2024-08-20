inline FBB::TableSupport::const_iterator FBB::TableSupport::end(size_t row) const
{
    const_iterator ret(*this, row, false);
    return ret;
}
