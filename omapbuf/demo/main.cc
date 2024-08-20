#define XERR
#include "main.ih"

int main(int argc, char **argv)
try
{
    string line;
    ifstream in{ argv[1] };

    Omapbuf buffer(argv[2], ios::in | ios::out);
//    Omapbuf buffer(argv[2], ios::in | ios::out | ios::app);

//                   ios::in | (fs::exists(argv[2]) ? ios::app : ios::trunc)
//                );  // append to existing file

    ostream out{ &buffer };     // file to write

//    out << "hello world" << endl;
//return 0;

//    out.seekp(20);

//
//    getline(in, line);
//    out << line << '\n';
//
//return 0;


        // arg 4: 'l' - write lines, 'w' - raw writes, 'r' (default: rdbuf)
    switch (argc == 4 ? *argv[3] : 'r')
    {
        case 'r':
            out << in.rdbuf();                // block-wise insertion
        break;

        case 'l':        
            while (getline(in, line))           // line-wise insertion
                out << line << '\n';
        break;

        case 'w':
            while (getline(in, line))           // raw writes
            {
                line += '\n';
                out.write(line.c_str(), line.length());
            }
        break;

        default:
            cout << "in out [l(ine), r(rdbuf), w(write)]\n";
        break;
    }

xerr("DONE");

}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
    return 1;
}
