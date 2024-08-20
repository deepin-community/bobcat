#include <fstream>
#include <iostream>
#include <string>
#include <exception>
#include <filesystem>

#include "../mmapbuf"

using namespace std;
namespace fs = filesystem;
using namespace FBB;

char usage[] = R"(
    1 offset  - seekg offset on the 1st file
    2 offset  - seekp (= seekg) offset on the 2nd file
    b         - insert the 1st file's rdbuf to the 2nd file
    c         - clear the files
    f         - 2nd file's size
    g         - get a single character fm the 2nd file, writing to cout
    i nr      - insert nr lines from the 1st file into the 2nd file
    e nr      - extract nr lines from the 2nd file into cout
    p         - put a single character fm the 1st file to the 2nd file
    q         - quit
    s         - sync the 2nd file
    t         - 2nd file's tellp (= tellg)
    r nr      - read  nr chars from the 2nd file, writing them to cout
    w nr      - write nr chars from the 1st file to the 2nd file
)";

int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        cout << "1st argument: input file, 2nd arg: input/output file\n";
        return 1;
    }

    ifstream in(argv[1]);

    MmapBuf buf(argv[2], 0,
                fs::exists(argv[2]) ? ios::in | ios::out : ios::out);

    iostream out(&buf);

    if (argc == 3)
        cout << usage << "\n"
            "bufSize: " << buf.bufSize() << "\n"
            "fileSize: " << buf.fileSize() << '\n';

    string line;
    size_t lineNr = 0;
    size_t value;
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
                cout << buf.fileSize() << '\n';
            break;

            case '1':
                line.front() = ' ';
                value = stoul(line);
                in.seekg(value);
            break;

            case 'e':
            {
                line.front() = ' ';
                
                size_t idx;
                for (idx = 0, value = stoul(line); idx != value; ++idx)
                {
                    if (not getline(out, line))
                        break;
                    cout << line << '\n';
                }
                cout << "extracted " << idx << " lines\n";
            }
            break;

            case 'i':
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

            case '2':
                line.front() = ' ';
                value = stoul(line);
                out.seekp(value);
            break;

            case 'g':
                cout << static_cast<char>(out.get()) << '\n';
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


            case 'r':
                line.front() = ' ';
                value = stoul(line);
                line.resize(value);
                out.read(&line.front(), value);
                value = out.gcount();
                cout.write(&line.front(), value);
                cout << "\ngot " << value << " chars from " << 
                        argv[2] << '\n';
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
    cerr << exc.what() << '\n';
    return 1;
}
