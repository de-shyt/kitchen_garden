#include <SFML/Graphics.hpp>
#include "Player.h"

void menu(sf::RenderWindow & window) {
    BaseElem NewGame = BaseElem(100, 30, 169, 39, "newgame.png");
    BaseElem Exit = BaseElem(100, 90, 110, 41, "exit.png");
    BaseElem Carrot = BaseElem(300, -20, 918, 950, "carrot.png");
    Carrot.mSprite.setRotation(15);

    bool isMenu = true;
    int menuNum = 0;

    while (isMenu)
    {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                isMenu = false;
                window.close();
            }
        }

        NewGame.mSprite.setColor(sf::Color::White);
        Exit.mSprite.setColor(sf::Color::White);

        menuNum = 0;
        window.clear(sf::Color(34, 177, 76));

        if (sf::IntRect(100, 30, 170, 60).contains(sf::Mouse::getPosition(window))) {
            NewGame.mSprite.setColor(sf::Color::Blue);
            menuNum = 1;
        }
        if (sf::IntRect(100, 90, 170, 50).contains(sf::Mouse::getPosition(window))) {
            Exit.mSprite.setColor(sf::Color::Blue);
            menuNum = 2;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (menuNum == 1) isMenu = false;
            if (menuNum == 2) { window.close(); isMenu = false; }

        }

        window.draw(Carrot.mSprite);
        window.draw(NewGame.mSprite);
        window.draw(Exit.mSprite);

        window.display();
    }
}
