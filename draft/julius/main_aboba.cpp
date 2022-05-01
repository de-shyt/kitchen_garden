#include <SFML/Graphics.hpp>
//#include "map.h"
#include "player.h"
#include "menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "POTATO SIMULATOR"/*, sf::Style::Fullscreen*/);
    menu(window);
//    window.setFramerateLimit(60);

    Player p("player.png", 100, 150, 8, 4, 50, 92);

    sf::Image map_image;
    map_image.loadFromFile("images/weed.jpg");
    sf::Texture map;
    map.loadFromImage(map_image);
    sf::Sprite s_map;
    s_map.setTexture(map);

    sf::Clock clock;
    float CurrentFrame = 0;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            p.go_left(CurrentFrame, time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            p.go_right(CurrentFrame, time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            p.go_up(CurrentFrame, time);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            p.go_down(CurrentFrame, time);
        p.update(time);

        window.clear();

        for(int i = 0; i < HEIGHT_MAP; ++i) {
            for(int j = 0; j < WIDTH_MAP; ++j) {
                /*if(TileMap[i][j] == '0')*/ {
                    s_map.setTextureRect(sf::IntRect(0, 0, 378, 376));
                }

                s_map.setPosition(j * 378, i * 376);
                window.draw(s_map);
            }
        }

        window.draw(p.sprite);
        window.display();
    }
}
