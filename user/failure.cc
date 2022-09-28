#include "user.ih"

// static
void User::failure()
{
    throw Exception{1} << 
        "Unable to determine actual user information from `/etc/passwd'";
}
