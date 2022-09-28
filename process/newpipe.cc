#include "process.ih"

void Process::newPipe(Pipe &pipe)
{
    pipe.close();
    pipe = Pipe{};
}
