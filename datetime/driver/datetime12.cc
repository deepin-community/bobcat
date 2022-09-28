#include <iostream>

#include "../datetime"

using namespace std;
using namespace FBB;

int main()
{
    cout << "Parsing various input text formats\n\n";

    cout << "format type 1 (Mon Jul 3 13:00:00 2018):\n";
    {
    
        DateTime utc{ "Mon Jul 3 13:00:00 2018", DateTime::UTC };
        cout << "Read as UTC time: " << utc << '\n';
        
        // Note: these time specifications do not honor DST
        
        DateTime local{ "Mon Jul 3 13:00:00 2018", DateTime::LOCALTIME };
        cout << "Read as LOCAL TIME: " << local << ",\n"
                "UTC obtained from LOCAL: " << local.utc() << '\n';
    }
    
    cout << "\n"
            "format type 2: (Mon Jul 3 13:00:00 CET 2018)\n";
    {
        DateTime utc{ "Mon Jul 3 13:00:00 CET 2018", DateTime::UTC };
        cout << "Read as UTC time: " << utc << '\n';
        
        DateTime local{ "Mon Jul 3 13:00:00 CET 2018", DateTime::LOCALTIME };
        cout << "Read as LOCAL TIME: " << local << ",\n"
                "UTC obtained from LOCAL: " << local.utc() << '\n';
    }
    
    cout << "\n"
            "format type 3 (Mon, 3 Jul 2018 13:00:00 +0100):\n";
    {
    
        DateTime utc{ "Mon, 3 Jul 2018 13:00:00 +0100", DateTime::UTC };
        cout << "Read as UTC time: " << utc << '\n';
        
        // Note: these time specifications do not honor DST
        
        DateTime local{ "Mon, 3 Jul 2018 13:00:00 +0100", 
                                                        DateTime::LOCALTIME };
        cout << "Read as LOCAL TIME: " << local << ",\n"
                "UTC obtained from LOCAL: " << local.utc() << '\n';
    }
    
    cout << "\n"
            "format type 4 (2018-12-03 13:00:00+01:00):\n";
    {
        DateTime utc{ "2018-12-03 13:00:00+01:00", DateTime::UTC };
        cout << "Read as UTC time: " << utc << '\n';

        
        DateTime local{ "2018-12-03 13:00:00+01:00", DateTime::LOCALTIME };
        cout << "Read as LOCAL TIME: " << local << ",\n"
                "UTC obtained from LOCAL: " << local.utc() << '\n';
    }
}








