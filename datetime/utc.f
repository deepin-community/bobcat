inline DateTime DateTime::utc() const
{
    return DateTime{ d_utcSec, UTC };
}
