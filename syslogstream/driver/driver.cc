/*
                              driver.cc
*/

#include <bobcat/syslogstream>
#include <iostream>

using namespace std;
using namespace FBB;


int main(int argc, char **argv)
{
    cout << "messages are logged in /var/log/user.log\n";

    SyslogStream sls(argv[0]);      // via an explicit SyslogStream

    sls << SyslogStream::notice << "Hello world 1" << endl;
}




