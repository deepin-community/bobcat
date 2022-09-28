//#define XERR

#include <iostream>
#include <string>
#include <exception>

#include <bobcat/csvtable> 

#include "../../xerr/xerr.ih"

using namespace std;
using namespace FBB;


int main(int argc, char **argv)
try
{
    CSVTable tab;
    tab.fmt("iteration, women years, total costs");

    tab << hline();
    tab.row("iteration, women years, total costs");
    tab << hline();
}
catch(int x)
{
    return x;
}
catch (exception const &exc)
{
    cerr << exc.what() << '\n';
}
catch (...)
{
    cerr << "unexpected exception\n";
    return 1;
}
