#ifndef FERMA_MAPWIDGET_H
#define FERMA_MAPWIDGET_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

struct unable_to_open_a_file : std::runtime_error {
    explicit unable_to_open_a_file(const std::string& filename);
};

struct MapWidget {
private:
    int x;
    int y;
    int Width;
    int Height;
    sf::Texture texture;

public:
    explicit MapWidget(int x_, int y_, int Width_, int Height_, std::string& filename);
    ~MapWidget();

    void Draw(sf::RenderWindow *Window);
};

struct MapApplication {
private:
    sf::RenderWindow *Window;
    MapWidget *Widget;

public:
    MapApplication();
    explicit MapApplication(std::string& filename);
    explicit MapApplication(std::string&& filename);
    ~MapApplication();

    void Run();

    void End();
};

#endif //FERMA_MAPWIDGET_H
