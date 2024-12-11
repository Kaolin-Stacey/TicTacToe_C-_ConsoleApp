//
// Created by kaoli on 2024-12-11.
//

#include "Network.h"

#include <iostream>

Network::Network()
    : socket_(ioContext_), acceptor_(ioContext_) {}

Network::~Network() {
    socket_.close();
}

void Network::startServer(unsigned short port) {
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), port);
    acceptor_.open(endpoint.protocol());
    acceptor_.bind(endpoint);
    acceptor_.listen();

    cout << "Server started on port " << port << endl;

    acceptor_.accept(socket_);
    cout << "Client connected" << endl;
}

void Network::connectToServer(const string &host, unsigned short port) {
    boost::asio::ip::tcp::resolver resolver(ioContext_);
    boost::asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(host, to_string(port));

    boost::asio::connect(socket_, endpoints);
    cout << "Connected to " << host << ":" << port << endl;
}

void Network::sendMessage(const string &message) {
    boost::asio::write(socket_, boost::asio::buffer(message+"\n"));
}

string Network::receiveMessage() {
    boost::asio::streambuf buffer;
    boost::asio::read_until(socket_, buffer, '\n');
    return boost::asio::buffer_cast<const char *>(buffer.data());
}
