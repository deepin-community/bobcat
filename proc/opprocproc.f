inline Proc::Activator operator|(Proc &lhs, Proc &rhs)
{
    return operator|(Proc::Activator{ lhs }, rhs);
}
