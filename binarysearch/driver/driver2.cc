#include <iostream>
#include <string>
#include "../binarysearch"

using namespace std;

struct Words
{
    string str;
    int value;
};

bool operator<(Words const &word, string const &str)
{
    return word.str < str;
}

bool operator<(string const &str, Words const &word)
{
    return str < word.str;
}

Words words[] = 
{
    { "eight", 0 },                // alphabetically sorted number-names
    { "five", 0 },
    { "four", 0 },
    { "nine", 0 },
    { "one", 0 },
    { "seven", 0 },
    { "six", 0 },
    { "ten", 0 },
    { "three", 0 },
    { "two", 0 }
};

int main()
{
    auto ret = FBB::binary_search(words, words + 10, "five", 
        [&](Words const &element, string const &value)
        {
            return element < value;
        }
    );

    cout << (ret != words + 10 ? "found it" : "not present") << '\n';
}









