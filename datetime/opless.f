inline bool operator<(FBB::DateTime const &left, FBB::DateTime const &right)
{
    return left.d_utcSec < right.d_utcSec;
}
