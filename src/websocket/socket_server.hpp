#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H

#include <WebSocketsServer.h>
#include "murli_command.hpp"

namespace Murli
{
    typedef std::function<void()> MeshConnectionEvent;
    typedef std::function<void(MurliCommand command)> MeshCommandEvent;

    class SocketServer
    {
        public:
            SocketServer();
            
            void loop();
            void broadcast(MurliCommand command);
            void onCommandReceived(MeshCommandEvent event);
            void onMeshConnection(MeshConnectionEvent event);

            uint32_t connectedClients();
        
        private:
            void serverEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length);

            MeshCommandEvent _meshCommandEvent = nullptr;
            MeshConnectionEvent _meshConnectionEvent = nullptr;
            WebSocketsServer _webSocket = WebSocketsServer(81);
    };
}

#endif // SOCKETSERVER_H