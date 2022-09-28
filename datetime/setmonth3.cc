#include "datetime.ih"

void DateTime::setMonth(Month month, Relative where)
{
     //    s  m  h  md          year
    TM ts{ 0, 0, 0, 0, month, d_tm.tm_year + 1900 };

    switch (where)
    {
        case NEXT:
                        // E.g., month == MAY, currently SEP: next year
                        //       month == SEP, currently SEP: next year
            if (static_cast<int>(month) <= d_tm.tm_mon)
                ++ts.tm_year;
        break;

        case LAST:
                        // E.g., month == OCT, currently SEP: previous year
                        //       month == SEP, currently SEP: previous year
            if (static_cast<int>(month) >= d_tm.tm_mon)
                --ts.tm_year;
        break;

        case THIS_YEAR:
        break;

        default:
        timeException();
    }

    setFields(ts, MONTH | YEAR);
}


