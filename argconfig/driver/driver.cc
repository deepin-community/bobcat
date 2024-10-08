#include <iostream>
#include <string>

#include "../argconfig"

#include <bobcat/exception>
#include <bobcat/ranger>
#include <bobcat/pattern>

using namespace std;
using namespace FBB;

namespace
{
    ArgConfig::LongOption lo[] =
    {
        ArgConfig::LongOption("option", 'o'),
        ArgConfig::LongOption("option-value", 'v')
    };
}

class X
{
    ArgConfig &d_arg;

    public:
        X();
        void function();
};

X::X()
:
    d_arg(ArgConfig::instance())
{}

void X::function()
{
    if (d_arg.nArgs() == 0)
        throw Exception() << "Provide the name of a config file as 1st arg";

    cout << "Counting " << d_arg.option('o') << " instances of -o or "
                                                        "--option\n"
            "Counting " << d_arg.option('v') << " instances of -v or "
                                                        "--option-value\n"
            "\n"
            "Now opening config file `" << d_arg[0] << "'\n";

    d_arg.open(d_arg[0]);       // Now open the config file explicitly
                            // (alternatively: use a constructor expecting
                            // a file name)

    cout << "\n"
            "ALL LINES IN THE CONFIG FILE:\n";
    copy(d_arg.begin(), d_arg.end(), ostream_iterator<string>(cout, "\n"));
    cout << "\n"
            "Counting " << d_arg.option('o') << " instances of -o or "
                                                            "--option\n";

    string optval;
    size_t count = d_arg.option(&optval, 'v');

    cout << "\n"
            "Counting " << count << " instances of -v or --option-value\n"
            "The first one having value `" << optval << "'\n"
            "Here are all their values:\n";

    auto iters = d_arg.beginEndRE("option-value");
    Pattern pattern( R"(^option-value:?\s+(.*)\s*$)" );

    for (auto &line: ranger(iters.first, iters.second))
    {
        cout << line << "\n";
        if (pattern << line)
            cout << "Tail: " << pattern[1] << '\n';
    }
}

int main(int argc, char **argv)
try
{
    ArgConfig &arg = ArgConfig::initialize("cov:", lo, lo + 2, argc, argv);

    if (arg.option('c'))
    {
        cout << "Comment lines are removed from the config file\n\n";
        arg.setCommentHandling(ArgConfig::RemoveComment);
    }

    X x;
    x.function();
}
catch (exception const &err)
{
    cout << "Terminating " << err.what() << endl;
    return 1;
}
