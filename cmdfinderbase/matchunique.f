inline bool FBB::CmdFinderBase::matchUnique(std::string const &key) const
{
    return key.find(d_cmd) != std::string::npos && d_cmd.length();
}
