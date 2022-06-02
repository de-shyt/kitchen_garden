#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>

struct Client {
    std::string name;
    sf::IpAddress ip;
    sf::TcpSocket socket;
    sf::Vector2f pos;
    sf::CircleShape shape;

    Client() {
        pos.x = 10, pos.y = 10;
    }

    explicit Client(std::string& name_, sf::IpAddress& ip_, sf::TcpSocket& socket_, int x, int y) :
        name(name_), ip(ip_)
    {
        pos.x = 10, pos.y = 10;
        shape = sf::CircleShape(20);
    }
};

struct Server {
    sf::TcpListener listener;
    sf::Packet packet;
    std::vector<Client*> client_vec;

    void draw(sf::RenderWindow& window) {
        window.clear();
        for (auto& client : client_vec) {
            client->shape.setPosition(client->pos.x, client->pos.y);
            window.draw(client->shape);
        }
        window.display();
    }
};



int main() {
    Server server;
    Client client;

    sf::TcpSocket socket; // to receive/send messages
    sf::TcpSocket socket2;
    // getRemoteAddress() and getRemotePort() can be used

    // sockets required: one listens for incoming connections and one for each connected client
    sf::Packet packet;	// for server

    char mode; // s[erver] or c[lient]

    std::cout << "who are you (s-server, c-client):";
    std::cin >> mode;

    std::string text;

    if(mode == 's') {
        std::cout << "your ip is:" << sf::IpAddress::getLocalAddress() << std::endl; // get address of the host
//        sf::TcpListener listener;
        server.listener.listen(2000);
        server.listener.accept(socket);
        text = "Hello new client ";

    } else if(mode == 'c') {

//        sf::IpAddress ip;
        std::cout << "enter ip: ";
        std::cin >> client.ip;
        std::cout << "enter name: ";
        std::cin >> client.name;
        text = client.name + " is here";

        auto status = socket.connect(client.ip, 2000);
        if (status == sf::Socket::Done) {
            server.client_vec.push_back(&client);
            text += client.name + '\n';
        }
        else {
            std::cout << "error while connecting to server\n";
            return 0;
        }
    }

    char buffer[100];
    size_t received;

    socket.send(text.c_str(), text.length() + 1);
    socket.receive(buffer, sizeof(buffer), received);
    std::cout << buffer << '\n';



    float x = 0, y = 0;
    sf::RenderWindow window(sf::VideoMode(800, 600), "window");
    sf::CircleShape shape(20);

    while(window.isOpen()){

        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                window.close();
            }

        }
        if (mode == 's')
        {
            socket.receive(packet);

            if (packet >> text) {
                std::cout << text;
            }

            server.draw(window);
        }

        else if (mode == 'c')
        {
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

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                std::cin >> text;
                packet.clear();
                packet << client.name << ": " << text << '\n';
                socket.send(packet);
            }
        }

        window.clear();

        for (auto& client : server.client_vec) {
            client->shape.setFillColor(sf::Color::Red);
            client->shape.setPosition(client->pos.x, client->pos.y);
            window.draw(client->shape);
        }

        shape.setPosition(x, y);
        window.draw(shape);
        window.display();
        sleep(sf::milliseconds(100));
    }
}
