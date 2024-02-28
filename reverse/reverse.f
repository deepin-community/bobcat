template <typename Type, bool isConst>
inline Reverse<Type, isConst>::Reverse(Type &type)
:
    d_type(type)
{}

template <typename Type, bool isConst>
inline Reverse<Type, isConst>::reverse_iter
                                    Reverse<Type, isConst>::begin() const
{
    return reverse_iter{ d_type.end() };
}

template <typename Type, bool isConst>
inline Reverse<Type, isConst>::reverse_iter
                                    Reverse<Type, isConst>::end() const
{
    return reverse_iter{ d_type.begin() };
}

template <typename Type>
inline auto reverse(Type &type)
{
    return Reverse<Type, false>{ type };
}

template <typename Type>
inline auto reverse(Type const &type)
{
    return Reverse<Type const, true>{ type };
}

template <typename Type>
inline auto reverse(Type &&type)
{
    return Reverse<Type, false>{ type };
}

template <typename Type, size_t size>
inline ReverseArray<Type, size>::ReverseArray(Type (&type)[size])
:
    d_type(type)
{}

template <typename Type, size_t size>
inline auto reverse(Type (&type)[size])
{
    return ReverseArray<Type, size>{ type };
}

template <typename Type>
inline ReverseSize<Type>::ReverseSize(Type *type, size_t size)
:
    d_type(type),
    d_size(size)
{}

template <typename Type>
inline auto reverse(Type *type, size_t size)
{
    return ReverseSize<Type>{ type, size };
}
