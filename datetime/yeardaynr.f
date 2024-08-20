inline unsigned FBB::DateTime::yearDayNr() const
{
    return d_tm.tm_yday + 1;
}
