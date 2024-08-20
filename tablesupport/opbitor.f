inline FBB::TableSupport::ColumnType operator|(FBB::TableSupport::ColumnType lhs,
                                          FBB::TableSupport::ColumnType rhs)
{
    return static_cast<FBB::TableSupport::ColumnType>(
                    static_cast<int>(lhs) | static_cast<int>(rhs));
}
