#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <iostream>
#include "TCPConnection.h"
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


class TCPServer {
public:
    //listen port
    TCPServer(int port);
    void listen();
    TCPConnection accept();
    void close();


private:
    //char _host_name[256];
    int _port;
    int _socket_handle;
    struct sockaddr_in _socket_addr;
    

};

#endif
