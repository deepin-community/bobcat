#include <fstream>
#include <iostream>
#include <string>
#include <exception>
#include <filesystem>

#include "../immapstream"

using namespace std;
namespace fs = filesystem;
using namespace FBB;

char usage[] = R"(
    b         - cp the file's rdbuf to cout
    c         - clear the file
    f         - file size
    g         - get a single character fm the file, writing to cout
    l nr      - insert nr lines from the file into cout
    o offset  - seekg offset 
    q         - quit
    r nr      - read  nr chars from the file, writing them to cout
    t         - tellg
)";

int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        cout << "1st argument: input file, 2nd arg (opt) mmap buf size\n";
        return 1;
    }

    ImmapStream in(argv[1], argv[2]);

    cout << usage << "\n"
            "bufSize: " << in.bufSize() << "\n"
            "fileSize: " << in.fileSize() << '\n';

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
                cout << in.rdbuf();
            break;

            case 'c':
                in.clear();
            break;

            case 'g':
                cout << static_cast<char>(in.get()) << '\n';
            break;

            case 'l':
            {
                line.front() = ' ';
                
                size_t idx;
                for (idx = 0, value = stoul(line); idx != value; ++idx)
                {
                    if (not getline(in, line))
                        break;
                    cout << line << '\n';
                }
                cout << "inserted " << idx << " lines\n";
            }
            break;

            case 'o':
                line.front() = ' ';
                value = stoul(line);
                in.seekg(value);
            break;

            case 'q':
                cout.put('\n');
            return 0;

            case 'r':
                line.front() = ' ';
                value = stoul(line);
                line.resize(value);
                in.read(&line.front(), value);
                value = in.gcount();
                cout.write(&line.front(), value);
                cout << "\ngot " << value << " chars from " << 
                        argv[1] << '\n';
            break;

            case 't':
            break;

            default:
                cout << "undefined input: `" << line << "'\n";
            break;
        }
        value = in.tellg();
        cout.clear();
        cout << "in OK: " << in.good() << ", at offset " << value << '\n';
    }
}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
    return 1;
}


