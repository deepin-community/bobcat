inline FBB::TableBase::Element &FBB::TableBase::vIndex(size_t row, size_t col)
{
    return d_string[col * d_nRows + row];
}
