#include "arg.ih"

    // accept: use -'accept' instead of --
    // opstring[0] == '+': accept undefined options

namespace
{
    char dashes[] = "--";
}

Arg__::Arg__(int accept, char const *optstring, 
         LongOption const *const begin, LongOption const *const end,
         int argc, char **argv)
:
    d_argv0(argv[0]),
    d_argPointer(0)
{
    string dashesArg;

    if (accept == 0)
        d_dashes = find(argv, argv + argc, string{ "--" } ) - argv;
    else
    {
        char acceptOpt[] = { '-', static_cast<char>(accept), 0  };

        d_dashes = find_if(argv, argv + argc, 
                                    [&](string const &arg)
                                    {
                                        return arg.find(acceptOpt) == 0;
                                    }
                                )  - argv;

        if (d_dashes != argc)
        {
            dashesArg = argv[d_dashes];
            argv[d_dashes] = dashes;
        }
    }

    setBasename();

    bool acceptUnspecified = *optstring == '+';   // accept unspecified opts
    if (acceptUnspecified)                        // and skip over the '+'
        ++optstring;

    string opts(*optstring == ':' ? "" : ":");  // ensure initial char is ':'
                                    // (returns : when a required argument is
                                    // missing)
    opts += optstring;

    OptStructArray optStructs(end - begin + 1); // create array of n + 1 
                                                // structs for long options

    fillLongOptions(optStructs.get(), optstring, begin, end);

    int longOptionIndex;       // receives the index of the long options

    opterr = 0;                // prevent getopt() msgs to stderr

    while (true)
    {
        d_getOpt = getopt_long(argc,
                        argv, opts.c_str(), optStructs.get(), 
                        &longOptionIndex);

        switch (d_getOpt)
        {
            case -1:
            {
                d_dashes += (d_dashes != argc) - optind;

                copy(argv + optind, argv + optind + d_dashes, 
                        back_inserter(d_argv));

                size_t idx = d_argv.size();

                if (not dashesArg.empty())
                    d_argv.push_back(dashesArg);

                copy(argv + optind + d_dashes, argv + argc, 
                    back_inserter(d_argv));

                d_dashes = idx;
            }
            return;

            case ':':
                s_optChar[0] = optopt;
                d_msg = (optopt ? s_optChar : argv[optind - 1]);
            return;

            case '?':
                if (acceptUnspecified)
                {
                    if (optopt == 0)
                        d_argv.push_back(argv[optind - 1]);
                    else
                        d_argv.push_back(
                                    string{ '-', static_cast<char>(optopt) }
                               );
                    break;
                }

                s_optChar[0] = optopt;
                d_msg = (optopt ? s_optChar : argv[optind - 1]);
            return;

            case 0:
                if (plainLongOption(begin[longOptionIndex]))
                    break;

            [[fallthrough]];
            // FALLING THROUGH IF LONG OPTION IS ALSO SHORT CHAR OPTION
                // in which case d_getOpt is set to the corresponding short
                // char option

            default:
                addCharOption();
            break;    
        }
    }
}
