inline bool FBB::CmdFinderBase::matchExact(std::string const &key) const
{
    return d_cmd == key && d_cmd.length();
}
