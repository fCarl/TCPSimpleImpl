#include "TCPServer.h"

TCPServer::TCPServer(int port) {
    _port = port;
    //create socket
    if ((_socket_handle = socket(AF_INET, SOCK_STREAM, IPPROTO_IP)) < 0) {
        ::close(_socket_handle);
        //TODO:
        //throw exception
    }
    //set socket_addr infomation
    bzero(&_socket_addr, sizeof(sockaddr_in));
    _socket_addr.sin_family = AF_INET;
    _socket_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    _socket_addr.sin_port = htons(_port);

    //bind socket to socket_addr
    if (bind(_socket_handle, (struct sockaddr*)&_socket_addr, sizeof(struct sockaddr_in)) < 0) {
        ::close(_socket_handle);
        //TODO:
        //throw exception
    } 
}

void TCPServer::listen() {
    ::listen(_socket_handle, 1);
}

TCPConnection TCPServer::accept() {
    int connection_handle = ::accept(_socket_handle, NULL, NULL);
    TCPConnection tcp_connection(connection_handle);
    return tcp_connection;
}

void TCPServer::close() {
    ::close(_socket_handle); 
}

