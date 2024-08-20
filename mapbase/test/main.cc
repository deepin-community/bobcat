#include "main.ih"

//    argc == 2 and *argv[1] == 'r' then reading

int main(int argc, char **argv)
{
    prepare(argc, argv);

    while (get(fileSize, "file size"))
    {
        run();

        checkResize();                           // when writing
        cout << '\n';
    }
}



