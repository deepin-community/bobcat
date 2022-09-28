inline DateTime::TimeFields operator|(DateTime::TimeFields lhs,
                                      DateTime::TimeFields rhs)
{
    return static_cast<DateTime::TimeFields>
            (
                static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)
            );
}
