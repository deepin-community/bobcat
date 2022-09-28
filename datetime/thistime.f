inline DateTime DateTime::thisTime() const
{
    return DateTime{ d_utcSec, LOCALTIME };     // the computer's local time
}
