#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H
#include <iostream>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#include <errno.h>

class TCPConnection {
public:
    TCPConnection(int connection_handle);
    int read(std::string& buffer, int bufsize);
    void close();
    ~TCPConnection();

private:
    int _connection_handle;
    char* _read_buffer;
    int _current_bufsize;
};





#endif
