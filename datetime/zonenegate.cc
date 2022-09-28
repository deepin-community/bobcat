#include "datetime.ih"

// static
void DateTime::Zone::negate(string &shift)
{
    if (shift.empty())
        return;

    switch (shift[0])
    {
        case '+':
            shift[0] = '-';
        break;
        case '-':
            shift[0] = '+';
        break;
        default:
            shift.insert(shift.begin(), '-');
        break;
    }
}
