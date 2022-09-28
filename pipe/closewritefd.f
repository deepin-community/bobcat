inline void Pipe::closeWriteFd()
{
    close(WRITE);
}
