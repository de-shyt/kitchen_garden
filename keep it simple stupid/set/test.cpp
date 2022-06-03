#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>

struct Server {
    bool is_running = true;
    sf::IpAddress ip_address;
    unsigned short port;
    sf::TcpListener listener;
    sf::SocketSelector selector;
    int max_player_number = 10; // any number, don't overfill cause it will explode!
    int current_id = 0;
    int player_number = 0;

    std::vector<Player> player_list;
    char tmp[1400];

//    sf::Clock clock;

    Server() {
        listener.listen(listener.getLocalPort()); // 45000
        selector.add(listener);
        std::cout << "We are ready to accept new clients!" << std::endl;
    };
    void run() {
        while(is_running) {
            if(selector.wait()) {
                if(selector.isReady(listener)) { // is server ready to receive new connections
                    std::unique_ptr<sf::TcpSocket> temp_socket = std::make_unique<sf::TcpSocket>();
                    if(listener.accept(*temp_socket) == sf::Socket::Done) {
                        player_list.emplace_back(Player(&temp_socket, sf::Vector2f(10, 10), current_id));
                        selector.add(*player_list.back().getSocket());
                        player_number++;

                        sf::Packet out_packet;
                        out_packet << 0;
                        out_packet << current_id;

                        if(player_list.back().get_socket()->send(out_packet) != sf::Socket::Done)
                            std::cout << "error sending player index" << std::endl;
                        current_id++;
                    }
                } else { // receive data

                }
            }
        }
    };
    void send_packet(sf::Packet& packet);
};

int main() {


//struct Client {
//    std::string name;
//    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
//    sf::TcpSocket socket;
//    sf::Vector2f pos{10, 10};
//};
//
//struct Server {
//    sf::TcpListener listener;
//    sf::Packet packet;
//    std::vector<Client> client_vec;
//    sf::TcpSocket regSocket;
//};
//
//Server server;
//
//int main() {
//    server.listener.listen(2000);
//    sf::Packet packet;
//
//    while(true) {
//        if(server.listener.accept(server.regSocket) == sf::Socket::Status::Done) {
//            server.regSocket.receive(packet);
//
//            std::string name;
//            packet >> name;
//            Client new_clint;
//            server.client_vec.push_back(new_clint);
//            server.client_vec.back()
//        }





//    // sockets required: one listens for incoming connections and one for each connected client
//    sf::TcpSocket socket; // to receive/send messages
//    sf::TcpSocket socket2;
//    // getRemoteAddress() and getRemotePort() can be used
//
//    sf::Packet packet;	// for server (one for everyone)
//
//    char mode; // s[erver] or c[lient]
//
//    std::cout << "who are you (s-server, c-client):";
//    std::cin >> mode;
//
//    std::string text;
//    char buffer[100];
//    size_t received;
//
//    if(mode == 's') {
//        std::cout << "your ip is:" << sf::IpAddress::getLocalAddress() << std::endl; // get address of the host
//        sf::TcpListener listener;
//        listener.listen(2000);
//
//        while(true) {
//            listener.accept(socket);
//            listener.accept(socket2);
//
//            text = "Hello new client";
//
//            socket.send(text.c_str(), text.length() + 1);
//            socket.receive(buffer, sizeof(buffer), received);
//
//            socket2.send(text.c_str(), text.length() + 1);
//            socket2.receive(buffer, sizeof(buffer), received);
//
//            std::cout << buffer << '\n';
//        }
//
//    } else if(mode == 'c') {
//        sf::IpAddress ip;
//        std::cout << "insert ip:";
//        std::cin >> ip;
//        std::string name;
//        std::cout << "enter your name:";
//        std::cin >> name;
//        text = name + " IS HERE";
//
//        socket.connect(ip, 2000);
//        socket2.connect(ip, 2000);
//
//        socket.send(text.c_str(), text.length() + 1);
//        socket.receive(buffer, sizeof(buffer), received);
//        std::cout << buffer << '\n';
//    }





//    socket2.send(text.c_str(), text.length() + 1);
//    socket2.receive(buffer, sizeof(buffer), received);
//    std::cout << "WOW " << buffer << '\n';



//    float x = 0, y = 0;
//    sf::RenderWindow window(sf::VideoMode(800, 600), "window");
//    sf::CircleShape shape(10);
//
//    while(window.isOpen()){
//
//        sf::Event event;
//        while(window.pollEvent(event)) {
//            if(event.type == sf::Event::Closed){
//                window.close();
//            }
//        }

//        if(mode == 's'){
//            socket.receive(packet);
//            if(packet >> x >> y){
//                std::cout << x << ":" << y << std::endl;
//            }
//        }
//
//        if(mode == 'c'){
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//                x++;
//            }
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//                x--;
//            }
//
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//                y++;
//            }
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//                y--;
//            }
//
//            packet << x << y;
//            socket.send(packet);
//            packet.clear();
//        }
//        window.clear();
//        shape.setPosition(x, y);
//        window.draw(shape);
//        window.display();
//        sleep(sf::milliseconds(100)); // ??
//    }

}
