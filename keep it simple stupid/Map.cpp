#include "Player.h"

std::string Map::CheckBoundaries(sf::Vector2i& MousePos) const {
    if (Shop.mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
        return "Shop";
    }
    if (Pause.mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
        return "Menu";
    }
    if (Chat.mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
        return "Chat";
    }
    return "Map";
}

void Map::Draw(sf::RenderWindow &window) {
    for(int i = 0; i < 20; ++i) {
        for(int j = 0; j < 20; ++j) {
            BG.mSprite.setTextureRect(sf::IntRect(0, 0, 346, 333));
            BG.mSprite.setPosition(j * 346, i * 333);
            window.draw(BG.mSprite);
        }
    }
    window.draw(Shop.mSprite);
    window.draw(Chat.mSprite);
    window.draw(Pause.mSprite);
}
