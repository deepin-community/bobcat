#include "main.ih"

bool get(size_t &var, char const *prompt)
{
    string pos;

    cout << prompt << ": ";
    cin >> pos;
    if (pos.front() == '-')
        return false;

    var = stoul(pos);
    return true;
}

