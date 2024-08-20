#include "proc.ih"

int Proc::waitForChild()
{
    d_child = { Fork::waitForChild(), pid() };

                                    // process ends, reset admin to the 
                                    // default: not active, no local pipes,
    d_admin = LOCAL_PIPES;          //          no threads active

    d_pipesPtr = 0;

    return exitStatus();
}
