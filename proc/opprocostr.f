inline void operator|(Proc &proc, std::ostream &out)
{
    operator|(Proc::Activator{ proc }, out);
}
