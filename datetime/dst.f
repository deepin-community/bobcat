inline bool FBB::DateTime::dst() const
{
    return d_tm.tm_isdst == 1;
}
