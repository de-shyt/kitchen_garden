#include "BaseStruct.h"


Map::Map() :
        IsMove(nullptr), dx(0), dy(0),
        BG(BaseElem(0, 0, 2048, 2048, "grassBG.png")), Shop(BaseElem(50, 50, 100, 100, "shop.png")),
        Chat(BaseElem(50, 200, 100, 100, "chat.png")), Pause(BaseElem(1770, 50, 100, 100, "pause.png")) {}



Map::~Map() {
    for (auto& it : BoughtItems) {
        for (auto& elem : it.second) {
            delete elem;
        }
    }
}


std::string Map::CheckBoundaries(sf::Vector2i& MousePos)
{
    if (Shop.mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
        return "Shop";
    }
    if (Pause.mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
        return "Menu";
    }
    if (Chat.mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
        return "Chat";
    }
    for (auto& it : BoughtItems) {
        for (auto& elem : it.second) {
            if (elem->mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
                IsMove = elem;
                dx = MousePos.x - elem->mSprite.getPosition().x;
                dy = MousePos.y - elem->mSprite.getPosition().y;
                return "Map";
            }
        }
    }
    return "Map";
}


void Map::Draw(sf::RenderWindow &window, BaseElem& player)
{
    for(int i = 0; i < 20; ++i) {
        for(int j = 0; j < 20; ++j) {
            BG.mSprite.setTextureRect(sf::IntRect(0, 0, 346, 333));
            BG.mSprite.setPosition(j * 346, i * 333);
            window.draw(BG.mSprite);
        }
    }

    window.draw(player.mSprite);

    if (IsMove != nullptr) {
        IsMove->mSprite.setColor(sf::Color::Green);
        IsMove->x = sf::Mouse::getPosition(window).x - dx;
        IsMove->y = sf::Mouse::getPosition(window).y - dy;
    }

    for (auto& it : BoughtItems) {
        for (auto& elem : it.second) {
            elem->mSprite.setPosition(elem->x, elem->y);
            window.draw(elem->mSprite);
        }
    }

    window.draw(Shop.mSprite);
    window.draw(Chat.mSprite);
    window.draw(Pause.mSprite);
    Money.Draw(window);
}
