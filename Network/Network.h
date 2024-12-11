//
// Created by kaoli on 2024-12-11.
//

#ifndef NETWORK_H
#define NETWORK_H

#include <boost/asio.hpp>
using namespace std;

class Network {
public:
    Network();
    ~Network();

    void startServer(unsigned short port);
    void connectToServer(const string &host, unsigned short port);
    void sendMessage(const string &message);
    string receiveMessage();

private:
    boost::asio::io_context ioContext_;
    boost::asio::ip::tcp::socket socket_;
    boost::asio::ip::tcp::acceptor acceptor_;
};



#endif //NETWORK_H
