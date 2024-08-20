#define XERR

#include <fstream>
#include <iostream>
#include <string>
#include <exception>
#include <filesystem>

#include "../ommapstream"

using namespace std;
namespace fs = filesystem;
using namespace FBB;

char usage[] = R"(
    1 offset  - seekg offset on the 1st file
    2 offset  - seekp offset on the 2nd file
    b         - insert the 1st file's rdbuf into the 2nd file
    c         - clear the files
    f         - 2nd file's size
    l nr      - insert nr lines from the 1st file into the 2nd file
    p         - put a single character fm the 1st file into the 2nd file
    q         - quit
    s         - sync the 2nd file
    t         - 2nd file's tellp
    w nr      - write nr chars from the 1st file to the 2nd file
)";

int main(int argc, char **argv)
try
{

    if (argc == 1)
    {
        cout << "1st argument: input file, 2nd arg: output file, "
                "3rd opt. arg: buf size,\n"
                "4th opt. arg: 1: ios::ate, 2: ios::app, 3: both\n";
        return 1;
    }


    ifstream in(argv[1]);

    ios::openmode mode = 
                    fs::exists(argv[2]) ? ios::in | ios::out : ios::out;
    if (argc > 4)
    {
        char ch = *argv[4];
        mode |= ch == '1' ? ios::ate :
                ch == '2' ? ios::app :
                ch == '3' ? ios::ate | ios::app : 
                            ios::out;   // by default, no further action
    }

    OmmapStream out{ argv[2], argv[3], mode };
                

//    if (argc <= 3)
//        cout << usage << "\n"
    cout << 
            "bufSize: " << out.bufSize() << "\n"
            "fileSize: " << out.fileSize() << '\n';

    string line;
    size_t lineNr = 0;
    size_t value = 0;
    while (true)
    {
        cout << '\n' << ++lineNr << "? ";
        getline(cin, line);
        
        switch (line.front())
        {
            case 'b':
                out << in.rdbuf();
            break;

            case 'c':
                in.clear();
                out.clear();
            break;

            case 'f':
                cout << out.fileSize() << '\n';
            break;

            case 'l':
            {
                line.front() = ' ';
                
                size_t idx;
                for (idx = 0, value = stoul(line); idx != value; ++idx)
                {
                    if (not getline(in, line))
                        break;
                    out << line << '\n';
                }
                cout << "inserted " << idx << " lines\n";
            }
            break;

            case '1':
                line.front() = ' ';
                value = stoul(line);
                in.seekg(value);
            break;

            case '2':
                line.front() = ' ';
                value = stoul(line);
                out.seekp(value);
            break;

            case 'p':
                out << static_cast<char>(in.get());
            break;

            case 'q':
                cout.put('\n');
            return 0;

            case 's':
                out.flush();
            break;

            case 't':
            break;

            case 'w':
                line.front() = ' ';
                value = stoul(line);
                line.resize(value);
                in.read(&line.front(), value);
                value = in.gcount();
                out.write(&line.front(), value);
                cout << "\nwrote " << value << " chars from " << 
                        argv[1] << " to " << argv[2] << '\n';
            break;

            default:
                cout << "undefined input: `" << line << "'\n";
            break;
        }
        value = out.tellp();
        cout << "in OK: " << in.good() << ", out OK: " << out.good() << 
                ", at " << value << '\n';
    }
}
catch (exception const &exc)
{
    cout << exc.what() << '\n';
    return 1;
}
