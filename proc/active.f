inline bool Proc::active() const
{
    return kill(pid(), 0) == 0;
}
