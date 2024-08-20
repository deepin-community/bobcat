inline FBB::DateTime FBB::DateTime::utc() const
{
    return DateTime{ d_utcSec, UTC };
}
