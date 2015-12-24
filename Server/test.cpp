#include "TCPServer.h"
#include <iostream>

using namespace std;

int main() {
    TCPServer tcp_ser(8080);
    tcp_ser.listen();
    TCPConnection tcp_con = tcp_ser.accept();
    string buffer;
    tcp_con.read(buffer, 100);
    cout << "Has read: " << buffer << endl;
}
