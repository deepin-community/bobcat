template <typename Iterator, typename Type, typename Comparator>
Iterator binary_search(Iterator begin, Iterator end, Type const &value, 
                       Comparator comparator)
{
        // note: the comparator's lhs parameter is an element in
        //       the begin..end range, its rhs parameter is 'value'

    auto iter = std::lower_bound(begin, end, value, comparator);
    return not (iter == end) and not (value < *iter) ? iter : end;
}
