inline char const **FBB::Glob::mend() const
{
    return const_cast<char const **>(d_share->end);
}
