#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>

struct Client {
    std::string name;
    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    sf::TcpSocket socket;
    sf::Vector2f pos{10, 10};
};

struct Server {
    sf::TcpListener listener;
    sf::Packet packet;
    std::vector<Client> client_vec;
};

//Server server;


int main() {
    sf::TcpSocket socket; // to receive/send messages
    sf::TcpSocket socket2;
    // getRemoteAddress() and getRemotePort() can be used

    // sockets required: one listens for incoming connections and one for each connected client
    sf::Packet packet;	// for server

    char mode; // s[erver] or c[lient]

    std::cout << "who are you (s-server, c-client):";
    std::cin >> mode;

    if(mode == 's') {
        std::cout << "your ip is:" << sf::IpAddress::getLocalAddress() << std::endl; // get address of the host
        sf::TcpListener listener;
        listener.listen(2000);
        listener.accept(socket);
    } else if(mode == 'c') {
        sf::IpAddress ip;
        std::cout << "insert ip:";
        std::cin >> ip;

        socket.connect(ip, 2000);
    }

    char buffer[100];
    size_t received;

    socket.send("Hello new client", 17);
    socket.receive(buffer, sizeof(buffer), received);
    std::cout << buffer << '\n';



    float x = 0, y = 0;
    sf::RenderWindow window(sf::VideoMode(800, 600), "server's window");
    sf::CircleShape shape(10);

    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                window.close();
            }

        }
        if(mode == 's'){
            socket.receive(packet);
            if(packet >> x >> y){
                std::cout << x << ":" << y << std::endl;
            }
        }

        if(mode == 'c'){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                x++;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                x--;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                y++;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                y--;
            }

            packet << x << y;
            socket.send(packet);
            packet.clear();
        }
        window.clear();
        shape.setPosition(x, y);
        window.draw(shape);
        window.display();
        sleep(sf::milliseconds(100));
    }
}
