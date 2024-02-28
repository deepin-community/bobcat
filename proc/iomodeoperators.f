inline Proc::IOMode operator|(Proc::IOMode lhs, Proc::IOMode rhs)
{
    return static_cast<Proc::IOMode>(
                static_cast<size_t>(lhs) | static_cast<size_t>(rhs));
}

inline Proc::IOMode &operator|=(Proc::IOMode &lhs, Proc::IOMode rhs)
{
    reinterpret_cast<size_t &>(lhs) |= static_cast<size_t>(rhs);
    return lhs;
}

inline Proc::IOMode operator&(Proc::IOMode lhs, Proc::IOMode rhs)
{
    return static_cast<Proc::IOMode>(
                static_cast<size_t>(lhs) & static_cast<size_t>(rhs));
}

inline Proc::IOMode &operator&=(Proc::IOMode &lhs, Proc::IOMode rhs)
{
    reinterpret_cast<size_t &>(lhs) &= static_cast<size_t>(rhs);
    return lhs;
}

inline Proc::IOMode operator~(Proc::IOMode mode)
{
    return static_cast<Proc::IOMode>(
                ~static_cast<size_t>(mode) & Proc::IOMODES);
}
