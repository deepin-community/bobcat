//#define XERR

 
#include <string>
#include <iostream>
#include <fstream>
#include <exception>

#include <bobcat/proc>

using namespace std;
using namespace FBB;

int main(int argc, char **argv)
try
{
//    [[maybe_unused]] char const prog[] = "./cincoutcerr";
    [[maybe_unused]] char const prog[] = "/bin/cat";

    Proc proc{
                argc == 1 ? "/bin/ls" : argv[1] 
                //, Proc::NONE
                //, Proc::CIN 
                //, Proc::MERGE_COUT_CERR
                //, Proc::CIN | Proc::MERGE_COUT_CERR
                //, Proc::CIN | Proc::COUT | Proc::IGNORE_CERR
                //, Proc::CIN | Proc::COUT
                //, Proc::CIN | Proc::CERR
                //, Proc::CIN | Proc::IGNORE_COUT | Proc::IGNORE_CERR
                //, Proc::CIN | Proc::IGNORE_COUT | Proc::CERR
             };

//    proc.pipeSignal(false);
    proc.setCommand(prog);

    [[maybe_unused]] Proc proc2{ "/bin/cat"
                //, Proc::CIN | Proc::COUT  | Proc::IGNORE_CERR
                //, Proc::CIN | Proc::COUT  | Proc::CERR
             };
    [[maybe_unused]] Proc proc3{ "/bin/cat" 
                //, Proc::CIN | Proc::IGNORE_COUT | Proc::IGNORE_CERR
            };
    
    // https://stackoverflow.com/questions/16219912/how-to-avoid-a-broken-pipe

//    signal(SIGPIPE, SIG_IGN);
//    proc.pipeSignal(false);

//    ifstream in{"cin"};         // reading twice via piping
    ifstream in{"xref"};         // reading twice via piping
//    ofstream out{ "/tmp/out" };

//    proc.setTimeLimit(1);

                                // also with setTimeLimit:
     proc.start();               // piping after start()-finish() is OK
    proc << in.rdbuf();

//    proc << cin.rdbuf();

     proc.finish();
    in.seekg(0);

//return 0;

    cout << "\n2 --------------\n\n";

//

//    "main.ih" | proc | "/tmp/out";
//    "main.ih" | proc | cout;

//    in | proc | cout;
//    in | proc | proc2 | cout;

//    proc.showMode("1");
//    proc2.showMode("2");
//    proc3.showMode("3");

    in | proc | proc2 | proc3 | cout;

//    cerr << proc3.exitStatus() << ' ' << proc3.procIdx() << '\n';
//return 0;

    cout << "\n3 --------------\n\n";

    in.seekg(0);
    proc.start();
    proc << in.rdbuf();
    proc.finish();

return 0;    


//    proc.useOut("/tmp/out");
//    proc.useMerge(cout);

//    proc.start(Proc::IGNORE_COUT | Proc::CIN);

//    proc.start();

//    proc.start(Proc::CIN | Proc::MERGE_COUT_CERR);

//    proc << cin.rdbuf();

//    in | proc;                      // (use a.out /bin/cat)

//    in.seekg(0);
//    in | proc;

//    in | proc | out;
//    in | proc | cout;
return 0;

    proc.start();
//    proc << in.rdbuf();
//    proc << cin.rdbuf();
    proc.finish();

return 0;

    //proc.stop();

//    proc = "/bin/cat";                // set and start

    proc.setCommand("/bin/cat");        // starting again using /bin/cat

//proc.showMode("before useOut");
//    proc.useOut(cout);
//proc.showMode("after useOut");

    proc.start();

    proc << "hello world\n";
    proc.finish();
}
catch (int x)
{
    if (x != 0)
        cerr << x << " exception\n";
}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
}
catch (...)
{
    cerr << "Exception caught\n";
}
