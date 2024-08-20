inline void FBB::DateTime::setMonthNr(int monthNr)
{
    setMonth(static_cast<int>(monthNr - 1));
}
