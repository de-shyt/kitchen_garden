#include "Player.h"


void Menu::Draw(sf::RenderWindow &window) const {
    window.draw(Carrot.mSprite);
    window.draw(NewGame.mSprite);
    window.draw(Exit.mSprite);
}


void Menu::ChangeColor(sf::RenderWindow &window) {
    NewGame.mSprite.setColor(sf::Color::White);
    Exit.mSprite.setColor(sf::Color::White);
    if (sf::IntRect(100, 30, 170, 60).contains(sf::Mouse::getPosition(window))) {
        NewGame.mSprite.setColor(sf::Color::Blue);
    }
    if (sf::IntRect(100, 90, 170, 50).contains(sf::Mouse::getPosition(window))) {
        Exit.mSprite.setColor(sf::Color::Blue);
    }
}


std::string Menu::CheckBoundaries(sf::Vector2i& MousePos) const {
    if (NewGame.mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
        return "Map";
    }
    if (Exit.mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
        return "CloseWindow";
    }
    return "Menu";
}
