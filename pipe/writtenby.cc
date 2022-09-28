#include "pipe.ih"

void Pipe::writtenBy(int fd)        // fd rather than the pipe's write fd
{                                   // is used to write to the pipe

    close(READ);              // we're writing, not reading

    Redirector  redirector{ d_fd[WRITE] };  // perform the redirection:
    redirector.swallow(fd);                 // fd writes

    close(WRITE);             // we don't need this anymore.
}
