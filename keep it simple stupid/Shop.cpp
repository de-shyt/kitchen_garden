#include "Player.h"

Shop::Shop() :
        BG(BaseElem(0, 0, 2048, 2048, "shopBG.png")),
        Close(BaseElem(1770, 50, 100, 100, "close.png")),
        Frame(BaseElem(220, 220, 360, 360, "frame.png"))
{
    Items.push_back(new BaseElem(0, 0, 280, 280, "gryadkaIcon.png"));
    Items.push_back(new BaseElem(0, 0, 360, 360, "donut.png"));
    Items.push_back(new BaseElem(0, 0, 360, 360, "diploma.png"));
}


Shop::~Shop() {
    for (auto& item : Items) {
        delete item;
    }
}

void Shop::Draw(sf::RenderWindow &window) {
    window.draw(BG.mSprite);
    window.draw(Close.mSprite);
    for (std::size_t i = 0; i < Items.size(); ++i) {
//        Frame.mSprite.setPosition(180 + 400 * (i % 4), 180 + 400 * (i / 4));
        window.draw(Frame.mSprite);
        Items[i]->mSprite.setPosition(180 + 400 * (i % 4), 180 + 400 * (i / 4));
        window.draw(Items[i]->mSprite);
    }
}

std::string Shop::CheckBoundaries(sf::Vector2i& MousePos) const {
    if (Close.mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
        return "Map";
    }
    return "Shop";
}


void Shop::ChangeColor(sf::RenderWindow& window, sf::Vector2i& MousePos) {
    Frame.mSprite.setColor(sf::Color::Transparent);
    Frame.mSprite.setPosition(180, 180);
    for (std::size_t i = 0; i < Items.size(); ++i) {
        if (Items[i]->mSprite.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
            Frame.mSprite.setPosition(180 + 400 * (i % 4), 180 + 400 * (i / 4));
            Frame.mSprite.setColor(sf::Color::Black);
        }
    }
}
