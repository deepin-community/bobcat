#include <iostream>

#include "../datetime"

using namespace std;
using namespace FBB;


int main()
try
{

    DateTime::Zone zone{"+1:00"};
    cout << "1. dst: " << zone.dstSeconds() << 
                        ", spec: "  << zone.spec() << "\n\n";

    zone = DateTime::Zone("CET");
    cout << "2. dst (3600): " << zone.dstSeconds() << ", spec: "  << 
            zone.spec() << "\n\n";

    zone = DateTime::Zone(":Asia/Calcutta");
    cout << "3. dst (3600): " << zone.dstSeconds() << ", spec: "  << 
            zone.spec() << "\n\n";

    zone = DateTime::Zone("+1:00", "+1:00");
    cout << "4. dst (3600): " << zone.dstSeconds() << ", spec: "  << 
            zone.spec() << "\n\n";

    zone = DateTime::Zone("+1:00", "+1:00", "Mar, last Sun", 
                                             "Oct, last Sun");
    cout << "5. dst (3600): " << zone.dstSeconds() << ", spec: "  << 
            zone.spec() << "\n\n";

    zone = DateTime::Zone("+1:00", "+1:00", "Mar, 1st Mon 2:00", 
                                             "Oct, 3rd Fri 3:00");
    cout << "6. dst (3600): " << zone.dstSeconds() << ", spec: "  << 
            zone.spec() << "\n\n";

    zone = DateTime::Zone::store("ZONE", "+1:00", "+1:00", 
                                    "Mar, last Sun", "Oct, last Sun");
    cout << "7. dst (3600): " << zone.dstSeconds() << ", spec: "  << 
            zone.spec() << "\n\n";

    zone = DateTime::Zone::store("ZONE", "+1:00", "-0:30", 
                                    "Mar, last Sun", "Oct, last Sun");
    cout << "8. dst (-1800): " << zone.dstSeconds() << ", spec: "  << 
            zone.spec() << "\n\n";
}
catch (exception const &exc)
{
    cout << exc.what() << "\n\n";
}


