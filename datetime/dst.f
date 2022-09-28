inline bool DateTime::dst() const
{
    return d_tm.tm_isdst == 1;
}
