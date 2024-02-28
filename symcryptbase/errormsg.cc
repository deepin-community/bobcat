#include "symcryptbase.ih"

// static
string SymCryptBase::errorMsg()
{
    char buf[256];              // see 'man err_error_string'

    auto eCode = ERR_get_error();
    ostringstream out;
    out << "openssl error code: " << eCode << ". openssl error string: " <<
            ERR_error_string(eCode, buf);

    return out.str();
}
