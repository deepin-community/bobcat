#include <sys/types.h>
#include <signal.h>

#include <iostream>
#include <string>
#include <chrono>
#include <bobcat/fork>
#include <bobcat/semaphore>
#include <bobcat/sharedsegment>
#include <bobcat/sharedmutex>

using namespace std;
using namespace FBB;

class Wait: public Fork
{
    SharedSegment *d_shared;
    int d_id;
    SharedMutex *d_mutex;

    public:
        Wait();
        ~Wait();
        void childProcess() override;
        void parentProcess() override;
};

Wait::Wait()
:
    d_shared(SharedSegment::create(&d_id, 1, 100, 0700)),
    d_mutex(new (d_shared) SharedMutex)
{
    cout << "shared memory ID = " << d_id << '\n';
}

Wait::~Wait()
{
    d_mutex->~SharedMutex();
    SharedSegment::deleteSegment(d_id);
    cout << "deleted the shared memory\n";
}

void Wait::childProcess()
{
    Semaphore waiter{0};

    while (true)
    {
        waiter.wait_for(chrono::seconds(2));
        d_mutex->lock();
        cout << "child hello\n";
        d_mutex->unlock();
    }
}

void Wait::parentProcess()
{
    string line;
    do
    {
        cout << "press enter to allow the parent to locck\n";
        cin.ignore(100, '\n');
        d_mutex->lock();
        cout << "parent has the lock, press enter to continue "
                "(to end: some input)\n";
        getline(cin, line);
        d_mutex->unlock();
    }
    while (line.empty());

    kill(pid(), SIGTERM);
}


int main()
{
    Wait waiter;
    waiter.fork();
}
