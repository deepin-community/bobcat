#include "main.ih"

void checkResize()
{
    if (read)
        return;

    cout << "\nfinal file size: " << fileSize;

    if (realSize < fileSize)
        cout << ", truncated (resized) to " << realSize << '\n';
}
