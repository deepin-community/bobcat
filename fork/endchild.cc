#include "fork.ih"

int Fork::endChild() const
{
    bool active = false;

    if (kill(pid(), 0) == 0)    // the process is still active
    {
        active = true;
        kill(pid(), SIGTERM);   // force its end
        kill(pid(), SIGKILL);
    }
    
    int ret = waitForChild();
                                    // when active: -1 (forced end) 
    return not active ? ret : -2;   // otherwise the child's own exit value
}
