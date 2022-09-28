#include "driver.h"

#include <bobcat/pattern>

using namespace std;
using namespace FBB;

#include <algorithm>
#include <cstring>

void showSubstr(string const &str)
{
    static int count = 0;

    cout << "String " << ++count << " is '" << str << "'\n";
}

void match(Pattern const &patt, string const &text)
try
{
     Pattern pattern{ patt };

    pattern.match(text);

    Pattern p3(pattern);

    cout << "before:  " << p3.before() << "\n"
            "matched: " << p3.matched() << "\n"  
            "beyond:  " << pattern.beyond() << "\n"  
            "end() = " << pattern.end() << '\n';

    for (size_t idx = 0; idx != pattern.end(); ++idx)
    {
        string str = pattern[idx];

        if (str.empty())
            cout << "part " << idx << " not present\n";
        else
        {
            Pattern::Position pos = pattern.position(idx);

            cout << "part " << idx << ": '" << str << "' (" << 
                        pos.first << "-" << pos.second << ")\n";
        }
    }
}
catch (exception const &exc)
{
    cout << exc.what() << '\n';
}

int main(int argc, char **argv)
{
    string patStr = R"(\d+)";

    do
    {
        cout << "Pattern: '" << patStr << "'\n";
        try
        {
                // by default: case sensitive
                // use any args. for case insensitive
            Pattern patt(patStr, argc == 1);

            cout << "Compiled pattern: " << patt.pattern() << '\n';

            while (true)
            {
                cout << "string to match : ";

                string text;
                getline(cin, text);
                if (text.empty())
                    break;
                cout << "String: '" << text << "'\n";
                match(patt, text);
            }
        }            
        catch (exception const &exc)
        {
            cout << exc.what() << ": compilation failed\n";
        }

        cout << "New pattern: ";
    }
    while (getline(cin, patStr) and not patStr.empty());
}
