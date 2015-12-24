#include "TCPConnection.h"

TCPConnection::TCPConnection(int connection_handle) {
    if (connection_handle < 0) {
        //TODO:
        //throw exception
    }
    _connection_handle = connection_handle;
    _read_buffer = NULL;
    _current_bufsize = 0;
}

int TCPConnection::read(std::string& buffer, int bufsize) {
    //adjust the size of buffer to which _read_buffer points
    //if _read_buffer is NULL or length of the buffer is smaller than specified size
    if (_current_bufsize == 0) {
        _read_buffer = new char[bufsize];
        _current_bufsize = bufsize;
    } else if (_current_bufsize < bufsize) {
        delete _read_buffer;
        _read_buffer = new char[bufsize];
        _current_bufsize = bufsize;
    }

    int byte_num = recv(_connection_handle, _read_buffer, bufsize, 0);
    buffer.assign(_read_buffer, byte_num);
    return byte_num;
}

void TCPConnection::close() {
    ::close(_connection_handle);
}

TCPConnection::~TCPConnection() {
    if (_read_buffer != NULL) {
        delete _read_buffer;
    }
}
