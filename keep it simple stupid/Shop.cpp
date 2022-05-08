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

std::string Shop::CheckBoundaries(sf::Vector2i& MousePos) const {
    if (Close.mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
        return "Map";
    }
    for (auto& it : Items) {
        if (it.second->mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
            BuyItem(it.second);
            return "Map";
        }
    }
    return "Shop";
}


void Shop::BuyItem(BaseElem* item) const
{
    std::ofstream f("ShopDB.txt", std::ios::app);

    std::string ItemName = item->FileName.substr(0, item->FileName.find('.'));

    // TODO нуу как-то игрок выбирает типа куда поставить объект, да
    int x = rand() % 1920, y = rand() % 1080;

    f << ItemName << ' ' << std::to_string(x) << ' ' << std::to_string(y) << '\n';

    if (MapPtr->BoughtItems.count(ItemName) == 0) {
        MapPtr->BoughtItems.insert(std::make_pair(ItemName, new BaseElem(0, 0, item->w, item->h, ItemName + "32x32.png")));
    }
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
