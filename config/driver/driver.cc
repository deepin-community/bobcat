#include <iostream>
#include <iterator>

#include <bobcat/exception>
#ifdef BOBCAT
    #include <bobcat/config>
#else
    #include "configdir/config"
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

    Config cf(argv[1], Config::NoCase, Config::NoComment);

    cout << "opened: " << argv[1] << '\n';

    cout << "Got " << cf.size() << " lines\n\n";
  
#if 0  
    cf.open(argv[1]);

    cout << "opened again: " << argv[1] << "\n"
            "Got " << cf.size() << " lines\n" <<
            cf[0] << " from line " << cf.index(0) << "\n"
            "================\n";
#endif

#if 1
    cout << "all lines using iterators:\n";
    copy(cf.begin(), cf.end(), ostream_iterator<CF_Line>(cout, "\n"));
#endif

    
#if 0
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
    cout.put('\n');
#endif
    
#if 0
    while (true)
    {
        cout << "Enter ID  to search for (or just Enter): ";
        string param;
        if (!getline(cin, param) || !param.length())
            break;

        auto it = cf.findID(param);

        if (it != cf.end())
            cout << *it << ": at index " << cf.index(it) << '\n';
        else        
            cout << " < not found > " << '\n';
    }
    cout.put('\n');
#endif

#if 0
    while (true)
    {
        cout << "Enter Key  to search for (or just Enter): ";
        string param;
        if (!getline(cin, param) || !param.length())
            break;

        auto it = cf.findKey(param);

        if (it == cf.end())
            cout << " < not found > " << '\n';
        else        
            cout << *it << ": at index " << cf.index(it) << "\n"
                    "parts:\n" 
                    "   line nr: " << it->lineNr() << "\n" 
                    "   key:     " << it->key() << "\n"
                    "   value:   " << it->value() << "\n"
                    "   tail:    " << it->tail() << "\n"
                    "   next Nr: " << (++it)->lineNr() << '\n';
    }
    cout.put('\n');
#endif

#if 1
    while (true)
    {
        cout << "Finding all lines matching an ID.\n"
                "Enter the ID (or just Enter): ";
        string param;
        if (!getline(cin, param) || !param.length())
            return 0;
    
        auto [begin, end] = cf.beginEndID(param);
    
        cout << "Counting: " << (end - begin) << " matches\n";
        while (begin != end)
        {
            auto it = *begin++;

            cout << *it << ":\n"
                    "parts:\n" 
                    "   line nr: " << it->lineNr() << "\n" 
                    "   key:     " << it->key() << "\n"
                    "   value:   " << it->value() << "\n"
                    "   tail:    " << it->tail() << "\n";
        }
    }
#endif

#if 0
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
            auto it = *begin++;

            cout << *it << ": at index " << cf.index(it) << "\n"
                    "parts:\n" 
                    "   line nr: " << it->lineNr() << "\n" 
                    "   key:     " << it->key() << "\n"
                    "   value:   " << it->value() << "\n"
                    "   tail:    " << it->tail() << "\n";
        }
    }
#endif
}
catch (exception const &e)
{
    cout << "Fatal: " << e.what() << '\n';
    return 1;
}

