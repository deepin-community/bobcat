#include <iostream>
#include <string>
#include <exception>

#include <bobcat/clientsocket>
#include <bobcat/ofdstream>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
    if (argc != 3)
    {
        cerr << "Provide servername and port number\n";
        return 1;
    }

    size_t     port = stoul(argv[2]);
    ClientSocket client(argv[1], port);
    int fd = client.connect();
    string line;

    cout << "Connecting to socket " << fd << endl <<
            "address = " << client.dottedDecimalAddress() << ", " <<
                                                             endl <<
            "communication through port " << client.port() << endl;

    OFdStream out(fd);                // stream to write to

    while (true)
    {
                                // Ask for a textline, stop if
        cout << "? ";           // empty / none
        if (!getline(cin, line) || line.length() == 0)
            return 0;
        cout << "Line read: " << line << endl;

                                // Send the line to the server
        out << line.c_str() << endl;
        cout << "wrote line\n";
    }
}
catch (exception const &err)
{
    cerr << err.what() << "\n" <<
            "Can't connect to " << argv[1] << ", port " <<
            argv[2] << '\n';
    return 1;
}
