#include "proc.ih"

// overrides
void Proc::childRedirections()
{
        // all pipes before d_read are not used by this process and 
        // can be closed
    for (size_t idx = 0; idx != d_read; ++idx)
        (*d_pipesPtr)[idx].close();

    if (d_mode & CIN)
        (*d_pipesPtr)[d_read].readFrom(STDIN_FILENO);

    if (d_mode & MERGE_COUT_CERR)             //  cout/cerr to 1 pipe
    {
        int fd[] = { STDOUT_FILENO, STDERR_FILENO };
        (*d_pipesPtr)[d_writeOut].writtenBy(fd, 2);
    }
    else
    {    
        if (d_mode & (COUT | IGNORE_COUT))
            (*d_pipesPtr)[d_writeOut].writtenBy(STDOUT_FILENO);
    
        if (d_mode & (CERR | IGNORE_CERR))
            (*d_pipesPtr)[d_writeErr].writtenBy(STDERR_FILENO);
    }
}



