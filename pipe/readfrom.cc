#include "pipe.ih"

void Pipe::readFrom(int fd)         // read from file descriptor fd 
{                                   // instead of the pipe's fd

    close(WRITE);             // we're reading, not writing

    Redirector  redirect{ d_fd[READ] }; // perform the redirection: 
    redirect.swallow(fd);               // read from fd.

    close(READ);              // don't need this anymore, as fd is used
}
