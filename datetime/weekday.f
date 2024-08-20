inline FBB::DateTime::Weekday FBB::DateTime::weekday() const
{
    return static_cast<Weekday>(d_tm.tm_wday);
}
