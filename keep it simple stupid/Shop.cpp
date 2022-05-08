#include "Player.h"

Shop::Shop() : MapPtr(nullptr) {}

Shop::Shop(Map* map_ptr) :
        BG(BaseElem(0, 0, 2048, 2048, "shopBG.png")),
        Close(BaseElem(1770, 50, 100, 100, "close.png")),
        Frame(BaseElem(220, 220, 360, 360, "frame.png")),
        MapPtr(map_ptr)
    {
        Items["rabatka"] = new BaseElem(0, 0, 360, 360, "rabatka.png");
        Items["donut"] = new BaseElem(0, 0, 360, 360, "donut.png");
        Items["diploma"] = new BaseElem(0, 0, 360, 360, "diploma.png");
    }



Shop::~Shop() {
    for (auto& item : Items) {
        delete item.second;
    }
}

void Shop::Draw(sf::RenderWindow &window) {
    window.draw(BG.mSprite);
    window.draw(Close.mSprite);
    int coord = 0;
    for (auto it = Items.begin(); it != Items.end(); it++, coord++) {
        window.draw(Frame.mSprite);
        it->second->mSprite.setPosition(180 + 400 * (coord % 4), 180 + 400 * (coord / 4));
        window.draw(it->second->mSprite);
    }
}

std::string Shop::CheckBoundaries(sf::Vector2i& MousePos) const {
    if (Close.mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
        return "Map";
    }
    for (auto it = Items.begin(); it != Items.end(); it++) {
        if (it->second->mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {

            return "Map";
        }
    }
    return "Shop";
}


void Shop::ChangeColor(sf::RenderWindow& window, sf::Vector2i& MousePos) {
    Frame.mSprite.setColor(sf::Color::Transparent);
    Frame.mSprite.setPosition(180, 180);
    int coord = 0;
    for (auto it = Items.begin(); it != Items.end(); it++, coord++) {
        if (it->second->mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
            Frame.mSprite.setPosition(180 + 400 * (coord % 4), 180 + 400 * (coord / 4));
            Frame.mSprite.setColor(sf::Color::Black);
        }
    }
}
