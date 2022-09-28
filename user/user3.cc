#include "user.ih"

User::User(size_t uid)
{
    passwd *pwd;
    
    while ((pwd = getpwent()))
    {
        if (pwd->pw_uid == uid)
        {
            assign(pwd);            // assign pwd fields to this object;
            return;
        }
    }

    failure();
}





