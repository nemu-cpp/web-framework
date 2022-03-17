/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/ishiko-connection-engine/blob/main/LICENSE.txt
*/

#include "IshikoServer.hpp"

using namespace Ishiko;
using namespace std;

namespace Nemu
{

IshikoServer::IshikoServer(IPv4Address address, Port port, Error& error)
    : m_socket(address, port, error)
{
}

void IshikoServer::start()
{
    // TODO: as a quick hack we put the blocking stuff in a secondary thread
    m_acceptThread = thread(
        [this]()
        {
            // TODO: this is a temporary blocking implementation
            // TODO: handle error
            Error error;
            TCPClientSocket clientSocket = m_socket.accept(error);
            
            char buffer[1000];
            clientSocket.read(buffer, 1000, error);
            clientSocket.write("HTTP/1.1 404 Not Found", 22, error);


            // TODO: loop and do something with the connected stuff
        }
    );
}

void IshikoServer::stop()
{
    // TODO: for now send a dummy request to trigger the accept
    Error error;
    TCPClientSocket socket(error);
    socket.connect(m_socket.ipAddress(), m_socket.port(), error);
}

void IshikoServer::join()
{
    m_acceptThread.join();
}

bool IshikoServer::isRunning() const
{
    // TODO
    return false;
}

}
