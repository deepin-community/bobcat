inline FBB::TableBase::Element &FBB::TableBase::elementAt(size_t row, size_t col)
{
    return (this->*d_indexFun)(row, col);
}
