#include "Player.h"

Shop::Shop() = default;

Shop::~Shop() = default;

void Shop::Draw(sf::RenderWindow &window) const {
    window.draw(BG.mSprite);
    for (auto& item : Items) {
        window.draw(item.mSprite);
    }
    window.draw(Close.mSprite);
}

std::string Shop::CheckBoundaries(sf::Vector2i& MousePos) const {
    if (Close.mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
        return "Map";
    }
    return "Shop";
}

