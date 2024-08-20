
#include "ecdh.ih"

string const ECDH::s_digits{ "0123456789ABCDEF" };
string const ECDH::s_cipherName{ "AES-256-GCM" };

ECDH::CurveMap ECDH::s_curves;
