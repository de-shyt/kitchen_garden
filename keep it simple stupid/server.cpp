#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>

struct Client {
    std::string name;
    sf::UdpSocket* dataSocket;
    sf::Vector2f pos{0, 0};
};

struct Server {
public:
    sf::TcpListener listener;
    sf::TcpSocket regSocket;
    sf::Packet packet;
    std::vector<Client> clients;

    void init() {
        listener.listen(2000); //listener.getLocalPort()
    }

    void register_new_clients() {
        listener.accept(regSocket);
        regSocket.receive(packet);

        std::string name;
        packet >> name;
        Client new_client;
        clients.push_back(new_client);
        clients.back().name = name;
        clients.back().dataSocket = new sf::UdpSocket;
        clients.back().dataSocket->bind(2000);

        packet.clear();

        // ---- send_new_client_data_to_all ----
        if(clients.size() > 1) {
            for(int i = 0; i < clients.size() - 1; ++i) {

            }
        }
    }

};

Server server;


int main() {
    server.init();

    std::cout << "your ip is:" << sf::IpAddress::getLocalAddress() << std::endl; // get address of the host
    std::cout << "your port is:" << server.listener.getLocalPort() << std::endl; // port
    sf::Packet packet;

    while(true) {
        server.register_new_clients();

    }
}
