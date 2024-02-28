#include "inetaddress.ih"

std::string InetAddress::dottedDecimalAddress() const
{
    return GetHostent::addressToString("InetAddress::getAddress()",
                &d_address.sin_addr);
}
