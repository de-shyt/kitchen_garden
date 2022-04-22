#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include "MapWidget.h"

unable_to_open_a_file::unable_to_open_a_file(const std::string& filename) :
    std::runtime_error("Unable to open a file " + filename + "\n") {}





MapWidget::MapWidget(int x_, int y_, int W, int H, std::string& filename) : x(x_), y(y_), Width(W), Height(H) {
    std::ifstream f("C:/FERMA/pictures/" + filename);
    if (!f.is_open()) {
        throw unable_to_open_a_file(filename);
    }
    f.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    texture.loadFromFile("C:/FERMA/pictures/" + filename);
}

MapWidget::~MapWidget() = default;

void MapWidget::Draw(sf::RenderWindow *Window) {
    sf::Sprite SpriteStuff;
    SpriteStuff.setTexture(texture);
    SpriteStuff.setPosition((float) x, (float) y);

    float WidgetWidth = (float) Width / (float) texture.getSize().x;
    float WidgetHeight = (float) Height / (float) texture.getSize().y;

    SpriteStuff.setScale(WidgetWidth, WidgetHeight);

    Window->draw(SpriteStuff);
}





MapApplication::MapApplication() : Window(nullptr), Widget(nullptr) {}

MapApplication::MapApplication(std::string& filename) {
    Window = new sf::RenderWindow(sf::VideoMode(640, 640), "FERMA");
    try {
        Widget = new MapWidget(0, 0, 640, 640, filename);
    } catch (const std::exception& e) {
        std::cout << e.what();
    }
}

MapApplication::MapApplication(std::string&& filename) {
    Window = new sf::RenderWindow(sf::VideoMode(640, 640), "FERMA");
    try {
        Widget = new MapWidget(0, 0, 640, 640, filename);
    } catch (const std::exception& e) {
        std::cout << e.what();
    }
}

MapApplication::~MapApplication() = default;

void MapApplication::Run() {
    while (Window->isOpen()) {
        sf::Event event;
        while (Window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                Window->close();
            }
        }
        Window->clear();
        Widget->Draw(Window);
        Window->display();
    }
}

void MapApplication::End() {
    if (Window != nullptr) {
        delete Window;
        Window = nullptr;
    }
    if (Widget != nullptr) {
        delete Widget;
        Widget = nullptr;
    }
}

