#include "datetime.ih"

void DateTime::setWeekday(Weekday weekday, Relative where)
{
    int difference = static_cast<int>(weekday) - d_tm.tm_wday;

    switch (where)
    {
        case NEXT:
            difference += 7;
        break;

        case LAST:
            difference -= 7;
        break;

        case THIS_WEEK:
        break;

        default:
        throw Exception{ 1 } <<
                            "DateTime::setWeekday(): invalid Relative spec.";
    }

    setDay(d_tm.tm_mday + difference);
}
