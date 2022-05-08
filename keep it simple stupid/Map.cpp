#include "Player.h"


Map::Map() :
        BG(BaseElem(0, 0, 2048, 2048, "grassBG.png")), Shop(BaseElem(50, 50, 100, 100, "shop.png")),
        Chat(BaseElem(50, 200, 100, 100, "chat.png")), Pause(BaseElem(1770, 50, 100, 100, "pause.png")) {}



Map::~Map() {
    for (auto& it : BoughtItems) {
        delete it.second;
    }
}


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

    std::ifstream f("ShopDB.txt");

    std::string ItemName, str;
    float x, y;

    while (std::getline(f, str))
    {
        std::stringstream stream(str);
        stream >> ItemName >> x >> y;
        auto it = BoughtItems.find(ItemName);
        if (it == BoughtItems.end()) {
            it = BoughtItems.insert(std::make_pair(ItemName, new BaseElem(0, 0, 35, 35, ItemName + "32x32.png"))).first;
        }
        it->second->mSprite.setPosition(x, y);
        window.draw(it->second->mSprite);
    }

    window.draw(Shop.mSprite);
    window.draw(Chat.mSprite);
    window.draw(Pause.mSprite);
}
