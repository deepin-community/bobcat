#include "serversocket.ih"

SocketBase ServerSocket::accept()
{
    sockaddr_in address;

    socklen_t   size = sizeof(address);

    int sock =
            ::accept
            (
                socket(),
                reinterpret_cast<sockaddr *>(&address),
                &size
            );
        
    if (sock < 0)
        throw Exception{} << "ServerSocket::accept(): " << errnodescr;


    return makeBase(sock, address);
}



