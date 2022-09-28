#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include <bobcat/omutexstream>

using namespace std;
using namespace FBB;

OMutexStream mout(cout);

void run(int nr)
{
    for (size_t idx = 0; idx != 3; ++idx)
    {
        mout << "hello world 1 from thread " << nr << ": " << 
                log(rand()) << endl;

        this_thread::sleep_for(
                chrono::milliseconds(200 + rand() % 800));

       mout << "hello world 2 from thread " << nr << ": " << 
                log(rand()) << '\n';

        this_thread::sleep_for(
                chrono::milliseconds(200 + rand() % 800));
    }

    auto out{ mout.ostream() };
    cout << nr << ": " << out.tellp() << '\n';
}
        
int main()
{
    srand(time(0));

    thread t1(run, 1);
    thread t2(run, 2);
    thread t3(run, 3);
    thread t4(run, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}
