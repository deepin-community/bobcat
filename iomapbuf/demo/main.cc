#define XERR
#include "main.ih"

// arg 1: existing (input) file
// arg 2: output file (maybe existing, if not existing: created)
// actions:
//  b               - write the input file using its rdbuf() member
//  c               - clear the stream status
//  f               - flush the buffer
//  l nr            - write <nr> lines from the input file using <<
//  o offset        - to position offset
//  q               - quit
//  r nr            - read nr lines from the output file, writing to cout
//  w nr            - write <nr> lines from the input file using write



int main(int argc, char **argv)
try
{
    xerr("MAIN");

    ifstream in{ argv[1] };

//    Omapbuf buffer(argv[2], ios::in | ios::out);
    IOmapbuf buffer(argv[2], 
                    fs::exists(argv[2]) ? 
                        ios::in | ios::out
                    :
                        ios::in | ios::out | ios::trunc, 
                    "1K");

//    Omapbuf buffer(argv[2], ios::in | ios::out | ios::app);

//                   ios::in | (fs::exists(argv[2]) ? ios::app : ios::trunc)
//                );  // append to existing file

//    ostream io{ &buffer };

    iostream io{ &buffer };

    string line;
    size_t value;
    while (true)
    {
        cout << "? ";
        getline(cin, line);

        switch (line.front())
        {
            case 'b':
              io << in.rdbuf();                // block-wise insertion
            break;

            case 'c':
                io.clear();
            break;

            case 'f':
                io << flush;
            break;

            case 'l':
                while (getline(in, line))           // line-wise insertion
                    io << line << '\n';
            break;

            case 'o':
                line.front() = ' ';
                value = stoul(line);
                io.seekp(value);
//xerr("calling io.tellp");                
                cout << "at: " << io.tellp() << '\n';
//xerr("done calling io.tellp");                
            break;

            case 'q':
            return 0;

            case 'r':
                line.front() = ' ';
                
                for (value = stoul(line); value--; )
                {
                    if (not getline(io, line)) 
                        break;
                    cout << line << '\n';
                }
            break;

            case 'w':
                in.seekg(0);
                line.front() = ' ';
                for (value = stoul(line); value--; )
                {
                    if (not getline(in, line)) 
                        break;
                    io << line << '\n';
                }
            break;
    
            default:
                cout << "undefined: " << line << '\n';
            break;
        }
        cout << io.good() << '\n';
    }

//return 0;
//
//xerr("START");
//
////    io << "hello world" << endl;
//
//xerr("MID");
//
////    io.seekg(0);
////    cout << io.tellg() << '\n';
//
//xerr("END");
//
//
////    out.seekp(20);
//
//    string line;
//
////    getline(io, line);
////    cout << io.good() << ' ' << io.tellg() << '\n';
//    
////    cout << line << '\n';
//
//
////    out << line << '\n';
//
////return 0;
//
//        // arg 4: 'l' - write lines, 'w' - raw writes, 'r' (default: rdbuf)
//    switch (argc == 4 ? *argv[3] : 'r')
//    {
//        case 'r':
//            io << in.rdbuf();                // block-wise insertion
//        break;
//
//        case 'l':        
//            while (getline(in, line))           // line-wise insertion
//                io << line << '\n';
//        break;
//
//        case 'w':
//            while (getline(in, line))           // raw writes
//            {
//                line += '\n';
//                io.write(line.c_str(), line.length());
//            }
//        break;
//
//        default:
//            cout << "in out [l(ine), r(rdbuf), w(write)]\n";
//        break;
//    }
//
//    io.flush();
//
//    io.seekg(0);
//    cout << io.rdbuf();

}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
    return 1;
}



