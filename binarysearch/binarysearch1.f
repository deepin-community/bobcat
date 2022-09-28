template <typename Iterator, typename Type>
Iterator binary_search(Iterator begin, Iterator end, Type const &value)
{
    auto iter = std::lower_bound(begin, end, value);
    return not (iter == end) and not (value < *iter) ? iter : end;
}
