
#include "ecdh.ih"

// static
std::tuple<unsigned long, std::string> ECDH::lastError() 
{
    unsigned long error = ERR_peek_last_error();
    if (error == 0) 
        return { 0, "" };

    char errorString[256];
    ERR_error_string_n(error, errorString, sizeof(errorString));
    return { error, errorString };
}

