inline Proc::Activator operator|(std::string const &fname, Proc &proc)
{
    return { proc.setIn(fname) };
}
