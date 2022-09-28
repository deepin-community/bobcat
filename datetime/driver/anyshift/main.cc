#include "main.ih"

int main(int argc, char **argv)
{
//    if (argc == 1)
//        cout << "\n"
//            "   optionally specify:\n"
//            "   zone shift (hrs[.5]);  dst (minutes);  req. hours (opt)\n\n";

    getLocal();                 // find the computer's time zone and DST
//    getDesired(argc, argv);
//
//    showLocalTime();            // show the time info based on current zone
//    showDesiredTime();          // show the time if requested
//    changeHours();              // change the hours setting


    time_t remoteZone = 3 * 3600;
    time_t remoteDST  = 3600;
    time_t remoteShift = remoteZone + remoteDST;

    tm t1 = tm
        {
            11, 29, 13, 3,          // local time specification (+ 3 hrs UTC)
              11,
            2018
        };

    t1.tm_sec += thisZone - remoteShift; 
    time_t t1sec = mktime(&t1);

    t1sec += remoteShift;  // correction for remote time
    gmtime_r(&t1sec, &t1);
    cout << "specified hour 13, reconstructed hour: " << t1.tm_hour << '\n';

    t1 = tm
        {
            11, 29, 13, 3,          // local time specification (+ 3 hrs UTC)
              5,                    
            2018
        };

                                    // local computer time: WITHOUT DST!!
    t1.tm_sec += thisZone - remoteShift; 
    t1sec = mktime(&t1);

    t1sec += remoteShift;  // correction for remote time
    gmtime_r(&t1sec, &t1);
    cout << "specified hour 13, reconstructed hour: " << t1.tm_hour << '\n';

}


