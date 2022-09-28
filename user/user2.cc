#include "user.ih"

User::User(std::string const &name)
{
    struct passwd *pwd;
    
    while ((pwd = getpwent()))
    {
        if (name == pwd->pw_name)
        {
            assign(pwd);
            return;
        }
    }

    failure();
}





