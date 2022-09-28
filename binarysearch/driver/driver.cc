#include <iostream>
#include <string>
#include "../binarysearch"

using namespace std;

string words[] = 
{
    "eight",                // alphabetically sorted number-names
    "five",
    "four",
    "nine",
    "one",
    "seven",
    "six",
    "ten",
    "three",
    "two"
};

bool compFun(string const &left, string const &right)
{
    return left < right;
}

int main()
{
    string *ret = FBB::binary_search(words, words + 10, "five");
    if (ret != words + 10)
        cout << "five is at offset " << (ret - words) << endl;

    ret = FBB::binary_search(words, words + 10, "grandpa");
    if (ret == words + 10)
        cout << "grandpa is not the name of a number\n";

    ret = FBB::binary_search(words, words + 10, "five", 
        [&](string const &element, string const &value)
        {
            return element < value;
        }
    );

    if (ret != words + 10)
        cout << "five is at offset " << (ret - words) << endl;

    ret = FBB::binary_search(words, words + 10, "grandpa", compFun); 
                                                   // or use: Comparator()
    if (ret == words + 10)
        cout << "grandpa is not the name of a number\n";
}









