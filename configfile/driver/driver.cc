#include <iostream>
#include <iterator>

#include <bobcat/exception>
#ifdef BOBCAT
    #include <bobcat/configfile>
#else
    #include "configdir/configfile"
#endif

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        cout << "Need name of configfile\n";
        return 1;
    }

    ConfigFile cf(argv[1], ConfigFile::RemoveComment, 
                    ConfigFile::SearchCaseInsensitive, 
                    ConfigFile::StoreIndices);

    cout << "opened: " << argv[1] << '\n';

    cout << "Got " << cf.size() << " lines\n";
    
    cf.open(argv[1]);

    cout << "opened again: " << argv[1] << "\n"
            "Got " << cf.size() << " lines\n" <<
            cf[0] << " from line " << cf.index(0) << "\n"
            "================\n";

    copy(cf.begin(), cf.end(), ostream_iterator<string>(cout, "\n"));
    
    while (true)
    {
        cout << "Enter literal to search for (or just Enter): ";
        string param;
        if (!getline(cin, param) || !param.length())
            break;

        auto it = cf.find(param);

        if (it != cf.end())
            cout << *it << ": at index " << cf.index(it) << '\n';
        else        
            cout << " < not found > " << '\n';
    }
    
    while (true)
    {
        cout << "Enter RE to search for (or just Enter): ";
        string param;
        if (!getline(cin, param) || !param.length())
            break;

        auto it = cf.findRE(param);

        if (it != cf.end())
            cout << *it << ": at index " << cf.index(it) << '\n';
        else        
            cout << " < not found > " << '\n';
    }
    
    while (true)
    {
        cout << "Finding all lines matching a RE.\n"
                "Enter the RE (or just Enter): ";
        string param;
        if (!getline(cin, param) || !param.length())
            return 0;
    
        auto [begin, end] = cf.beginEndRE(param);
    
        cout << "Counting: " << (end - begin) << " matches\n";
        while (begin != end)
        {
            cout << *begin << '\n';
            ++begin;
        }
    
        cout << "value of findKey: " << cf.findKey(param) << '\n';
    }
}
catch (exception const &e)
{
    cout << "Fatal: " << e.what() << '\n';
    return 1;
}

