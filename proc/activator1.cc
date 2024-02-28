#include "proc.ih"

    // the first pipe is used by the first object forwarding its input
    // stream to its child.
    // the last pipe but one collects a child's cout info
    // the last pipe collects a child's cerr info
    // with multiple piped processes the last pipe is forwarded to the next
    // child's input stream

    //   | pipe[0]    - external info, read by the 1st child's CIN
    //   | pipe[1]    - the 1st child's CERR
    // | | pipe[2]    - the 1st child's COUT, 2nd child's CIN
    // | +--------    - pipe frame used by the 1st child
    // | pipe[5]      - the 2nd child's CERR
    // | pipe[4]      - the 2nd child's COUT, the 3rd child's CIN
    // | +--------    - pipe frame used by the 2nd child
    // ...          
    // | | pipe[#-3]  - the last but one's child's COUT, the last child's CIN
    // | +--------    - pipe frame used by the 1st child
    // | pipe[#-2]    - the last child's CERR
    // | pipe[#-1]    - the last child's COUT
    // | +--------    - pipe frame used by the last child

    // Each process uses three pipes, each new process adds two new pipes.
    // After defining the new pipes: 
    //         read     = size() - 3, 
    //         writeErr = size() - 2, 
    //         writeOut = size() - 1

Proc::Activator::Activator(Proc &proc)
:
    d_pipesPtr(new vector<Pipe>(1))     //  define one pipe
{
    add(proc);                          // add proc to d_procPtr
}

