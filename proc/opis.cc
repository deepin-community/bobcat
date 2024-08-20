#include "proc.ih"

int Proc::operator=(std::string const &cmd)
{
    int ret = stop();               // stop a currently running cmd

    setCommand(cmd);                // set the next cmd
    start();                        // start the command

    return ret;
}
