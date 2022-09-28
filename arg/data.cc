#include "arg.ih"

Arg     *Arg::s_arg;

string  Arg__::s_dirsep("/");
char    Arg__::s_optChar[] = " ";

char const Arg::s_alreadyInitialized[] = 
                        "Arg::initialize(): already initialized";
