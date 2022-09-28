#include "main.ih"

void getDesired(int argc, char **argv)    
{
    if (argc == 1)
    {
        desiredZone = thisZone;
        desiredDST = thisDST;
    }
    else
    {
        showDesired = true;

        desiredZone = stod(argv[1]) * 3600;      // seconds Zone
        desiredDST = stoi(argv[2]) * 60;         // seconds DST

        setHours = argc > 3;

        if (setHours)
            hours = stoi(argv[3]);

        cout << "desired zone: " << desiredZone / 3600. << " hours\n"
                "desired DST:  " << desiredDST / 60 << " minutes\n";
    
        if (setHours)
            cout << "change hours to " << hours << '\n';
    
        cout << '\n';
    }
}

