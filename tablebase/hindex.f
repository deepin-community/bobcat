inline FBB::TableBase::Element &FBB::TableBase::hIndex(size_t row, size_t col)
{
    return d_string[row * d_nColumns + col];
}
