#include "proc.ih"

Proc::Activator::~Activator()
{
                                    // a previously constructed Activator
    if (d_procPtr.empty())          // in a pipe-sequence, whose vectors were
        return;                     // already moved to the next Activator

    for (Proc *ptr: d_procPtr)      // start the child processes
        ptr->start();
                                    // back() writes to cout
    thread resultThread{ &Proc::toOut, d_procPtr.back() };

            
    d_procPtr.front()->readCin();   // read the input

                                    // close all Out/In pipes. Pipe 0 is for
                                    // readCin, Err pipes are handled next,
                                    // the last Out pipe is for resultThread
    for (size_t idx = 2, end = d_pipesPtr->size() - 1; idx != end; idx += 2)
        (*d_pipesPtr)[idx].close();

    for (Proc *ptr: d_procPtr)      // join the errThreads if active
        ptr->checkErrThread();

    resultThread.join();

    pid_t procIdx = 0;
    int procRet = 0;
    for (size_t idx = 0, end = d_procPtr.size(); idx != end; ++idx)
    {
        Proc *ptr = d_procPtr[idx];
                                    // return the first failing Proc's 
                                    // error code
        int ret = ptr->waitForChild();

        if (idx == 1 or (ret != 0 and procRet == 0))
        {
            procIdx = idx;
            procRet = ret;
        }
    }
    d_procPtr.back()->d_child = { procRet, procIdx };

    delete d_pipesPtr;
}




