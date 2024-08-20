inline char const **FBB::Glob::mbegin() const
{
    return const_cast<char const **>(d_share->begin);
}
