inline SocketBase SocketBase::makeBase(int socket, sockaddr_in const &address)
{
    return SocketBase{ socket, address };
}
