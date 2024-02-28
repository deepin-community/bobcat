#include "proc.ih"

void Proc::start(size_t timeLimit, IOMode mode, ProcType type, 
                 size_t bufferSize)
{
    if (active())
        stop();

    d_admin |= ACTIVE;
                                        // set/save the actual/current data
    preFork(mode, type, bufferSize, timeLimit);

    if (localPipes())                   // local I/O pipes are used
        getPipes();                     // d_read set to 0;

                                        // otherwise: d_read is set by pipes()
    d_writeErr = d_read + 1;
    d_writeOut = d_writeErr + 1;

    if (d_mode == REPLACE)
        childProcess();                 // update: no redirections
    else
        fork();

    beginTimerThread();                 // (maybe) begin the timer thread

    output(d_err);                      // (maybe) start the d_err thread

    if (not localPipes())               // piping forwards Pi's OUT to Pj's IN
        return;

    output(d_out);                      // (maybe) start the d_out thread

    if (mode & CIN)
        readCin();
    else
        closePipe(d_read);
}








