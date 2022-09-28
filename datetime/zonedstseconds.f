    // at this point DST is known to be active (cf. utcFromTM)
inline int DateTime::Zone::dstSeconds() const
{
    return d_data.dstSeconds;
}
