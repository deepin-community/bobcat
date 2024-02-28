#include <iostream>
#include <vector>

#include <bobcat/fswap>

using namespace std;
using namespace FBB;

int pCount = 0;

struct P
{
    vector<int> *d_i = 0;
    int d_id;

    struct A
    {
        std::vector<P *> d_p;
        std::vector<int> *d_i = 0;         // pipes passed to Proc objects
    
        A(P &p, int val)
        {
            if (d_i == 0)
                d_i = new vector<int>{ val };
            else
                d_i->push_back(val);
            p.d_i = d_i;
            d_p.push_back(&p);
        }

        A(A &&tmp, P &p)
        {
            fswap(*this, tmp);

            d_i->push_back(10 * p.d_id);
            p.d_i = d_i;
            d_p.push_back(&p);
        }

        A(A &&tmp)                  // gebruikt door op|
        {
            fswap(*this, tmp);
        }

        ~A()
        {
            if (d_p.size() != 0)
            {
                for (P *p: d_p)
                    p->out();
                delete d_i;
            }
        }
    };

    P()
    :
        d_id(++pCount)
    {}

    void out()
    {
        cout << "P " << d_id << ": ";
        if (d_i == 0)
            cout << "no entries";
        else
        {
            for (int val: *d_i)
                cout << val << ' ';
        }
        cout << "\n\n";
    }
};

P::A operator|(int val, P &p)
{
    return P::A{p, val};
}

P::A operator|(P::A &&tmp, P &p)
{
    return P::A{move(tmp), p};
}

    
int main()
{
    P p1;
    P p2;
    P p3;

    4 | p1 | p2 | p3;
}
