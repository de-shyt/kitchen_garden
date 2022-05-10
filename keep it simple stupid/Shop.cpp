#include "BaseStruct.h"


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

        int coord = 0;
        for (auto it = Items.begin(); it != Items.end(); it++, coord++) {
            it->second->x = 180 + 400 * (coord % 4);
            it->second->y = 180 + 400 * (coord / 4);
            it->second->mSprite.setPosition(it->second->x, it->second->y);
        }
    }



Shop::~Shop() {
    for (auto& item : Items) {
        delete item.second;
    }
}

void Shop::Draw(sf::RenderWindow &window) {
    window.draw(BG.mSprite);
    window.draw(Close.mSprite);
    for (const auto& it : Items) {
        window.draw(Frame.mSprite);
        window.draw(it.second->mSprite);
    }
}

std::string Shop::CheckBoundaries(sf::Vector2i& MousePos) {
    if (Close.mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
        return "Map";
    }
    for (auto& it : Items) {
        if (it.second->mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y))
        {
            std::string ItemName = it.second->FileName.substr(0, it.second->FileName.find('.'));
            MapPtr->BoughtItems[ItemName].push_back(new BaseElem(MousePos.x - 16, MousePos.y - 16, 32, 32, ItemName + "32x32.png"));
            return "Map";
        }
    }
    return "Shop";
}


void Shop::ChangeColor(sf::RenderWindow& window, sf::Vector2i& MousePos) {
    Frame.mSprite.setColor(sf::Color::Transparent);
    Frame.mSprite.setPosition(180, 180);
    for (const auto& it : Items) {
        if (it.second->mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
            Frame.mSprite.setPosition(it.second->x, it.second->y);
            Frame.mSprite.setColor(sf::Color::Black);
        }
    }
}
