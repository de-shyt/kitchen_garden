#include <SFML/Graphics.hpp>

void menu(sf::RenderWindow & window) {
    sf::Texture menuNewGame, menuExit;
    sf::Image menuCar;

    menuNewGame.loadFromFile("C:/FERMA/pictures/NewGameIcon.png");
    menuExit.loadFromFile("C:/FERMA/pictures/ExitIcon.png");
    menuCar.loadFromFile("C:/FERMA/pictures/CarrotIcon.png");
//    menuCar.createMaskFromColor(sf::Color(245, 245, 245));

    sf::Texture menuCarrot;
    menuCarrot.loadFromImage(menuCar);

    sf::Sprite menuNG(menuNewGame), menuEx(menuExit), menuCrot(menuCarrot);

    bool isMenu = 1;
    int menuNum = 0;

    menuNG.setPosition(100, 30);
    menuEx.setPosition(100, 90);
    menuCrot.setPosition(300, -20);
    menuCrot.setRotation(15);

    while (isMenu)
    {
        menuNG.setColor(sf::Color::White);
        menuEx.setColor(sf::Color::White);

        menuNum = 0;
        window.clear(sf::Color(34, 177, 76));

        if (sf::IntRect(100, 30, 300, 60).contains(sf::Mouse::getPosition(window))) { menuNG.setColor(sf::Color::Blue); menuNum = 1; }
        if (sf::IntRect(100, 90, 300, 50).contains(sf::Mouse::getPosition(window))) { menuEx.setColor(sf::Color::Blue); menuNum = 2; }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (menuNum == 1) isMenu = false;
            if (menuNum == 2) { window.close(); isMenu = false; }

        }

        window.draw(menuCrot);
        window.draw(menuNG);
        window.draw(menuEx);

        window.display();
    }
}
