    #include <iostream>
    #include "../datetime"

    using namespace std;
    using namespace FBB;

    int main()
    {
//info
DateTime dt{ 0, DateTime::UTC };    // set UTC at begin of era

tm era{ 0 };                        // define a tm with tm_mday == 1
era.tm_mday = 1;

dt -= era;                          // subtract from dt and display
cout << dt << endl;
//=
    }



