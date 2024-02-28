// free functions:
// ===============

inline std::istream &operator>>(std::istream &in, ReadLineHistory &history)
{
    return history.extract(in);
}

// ReadLineHistory:
// ================

inline ReadLineHistory::const_iterator ReadLineHistory::begin() const
{
    return const_iterator(d_elements, 0);
}

inline ReadLineHistory::const_iterator ReadLineHistory::end() const
{
    return const_iterator(d_elements);
}

inline size_t ReadLineHistory::maxSize() const
{
    return history_max_entries;
}

inline ReadLineHistory::const_reverse_iterator ReadLineHistory::rbegin() const
{
    return const_reverse_iterator(end());
}

inline ReadLineHistory::const_reverse_iterator ReadLineHistory::rend() const
{
    return const_reverse_iterator(begin());
}

inline ReadLineHistory &ReadLineHistory::setTimestampsIO(bool useTimestamps)
{
    d_timestamps = useTimestamps;
    return *this;
}

inline size_t ReadLineHistory::size() const
{
    return history_length;
}

inline bool ReadLineHistory::timestamps() const
{
    return d_timestamps;
}

// HistoryElement:
// ===============

inline char const *ReadLineHistory::HistoryElement::line() const
{
    return d_line;
}

inline char const *ReadLineHistory::HistoryElement::timestamp() const
{
    return d_timestamp;
}

// const_iterator:
// ===============

inline ReadLineHistory::const_iterator::const_iterator(
                                            ElementsConstPtr elements, 
                                            size_t idx)
:
    d_idx(idx),
    d_elements(elements)
{}

inline ReadLineHistory::const_iterator::const_iterator(
                                        ElementsConstPtr elements) 
:
    d_idx(history_length),
    d_elements(elements)
{}

inline ReadLineHistory::HistoryElement const
    *ReadLineHistory::const_iterator::operator->() const
{
    return &operator*();
}

inline bool ReadLineHistory::const_iterator::operator==(
                                            const_iterator const &rhs) const
{
    return d_idx == rhs.d_idx;
}

inline ReadLineHistory::const_iterator
    &ReadLineHistory::const_iterator::operator++()
{
    ++d_idx;
    return *this;
}

inline ReadLineHistory::const_iterator
    ReadLineHistory::const_iterator::operator++(int)
{
    return const_iterator(d_elements, d_idx++);
}

inline ReadLineHistory::const_iterator
    &ReadLineHistory::const_iterator::operator--()
{
    --d_idx;
    return *this;
}

inline bool ReadLineHistory::const_iterator::operator!=(
                                            const_iterator const &rhs) const
{
    return not (*this == rhs);
}

