inline void MultiBuf::insert(std::vector<stream> const &os)
{
    d_os.insert(d_os.end(), os.begin(), os.end());
}
