#include "Player.h"

Chat::Chat() = default;

Chat::~Chat() = default;

void Chat::Draw(sf::RenderWindow& window) const {
    window.draw(Close.mSprite);
};

std::string Chat::CheckBoundaries(sf::Vector2i& MousePos) const {
    if (Close.mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
        return "Map";
    }
    return "Chat";
}
