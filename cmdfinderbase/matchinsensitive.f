inline bool FBB::CmdFinderBase::matchInsensitive(std::string const &key) const
{
    return
        String::casecmp(d_cmd, key) == 0
        &&
        d_cmd.length();
}
