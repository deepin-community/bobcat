#include <iostream>
#include <vector>

#include <bobcat/reverse>

using namespace std;
using namespace FBB;

int main()
{
    int intArr[] = { 1, 2, 3, 4, 5};        // arrays of known sizes
    for (int value: reverse(intArr))
        cout << value << ' ';
    cout << '\n';

    for (int value: reverse(intArr, 5))     // using specified sizes
        cout << value << ' ';
    cout << '\n';

    int const constArr[] = { 1, 2, 3, 4, 5};// arrays with const elements
    for (int value: reverse(constArr))
        cout << value << ' ';
    cout << '\n';

    for (int value: reverse(constArr, 5))   // using specified sizes
        cout << value << ' ';
    cout << '\n';

    for (int value: reverse(intArr, 5))     // arrays of specified sizes
        cout << value << ' ';
    cout << '\n';


    vector<int> vi{ 1, 2, 3, 4, 5 };        // handle non-const objects
    for (int value: reverse(vi))
        cout << value << ' ';
    cout << '\n';

    vector<int> const cvi{ 1, 2, 3, 4, 5 }; // handle const objects
    for (int value: reverse(cvi))
        cout << value << ' ';
    cout << '\n';
                                            // handle lvalues
    for (int value: reverse(initializer_list<int>{ 1, 2, 4, 8 }))
        cout << value << ' ';
    cout.put('\n');
                                            // named constant objects
    auto ilist = initializer_list<int>{ 1, 2, 4, 8 };
    for (int value: reverse(ilist))
        cout << value << ' ';
    cout.put('\n');
}
