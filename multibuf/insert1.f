inline void MultiBuf::insert(std::ostream &os, Mode mode)
{
    d_os.push_back(stream(os, mode));
}
