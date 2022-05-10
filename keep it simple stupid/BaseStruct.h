#ifndef FERMA_BASESTRUCT_H
#define FERMA_BASESTRUCT_H


#include "TextElem.h"
#include "BaseElem.h"
#include <unordered_map>



struct BaseStruct {
    virtual std::string CheckBoundaries(sf::Vector2i& MousePos) = 0;
};


struct Menu : BaseStruct {
    TextElem NewGame;
    TextElem Continue;
    TextElem Settings;
    TextElem Exit;
    BaseElem Carrot;

    Menu();
    void Draw(sf::RenderWindow& window) const;
    void ChangeColor(sf::RenderWindow& window);
    std::string CheckBoundaries(sf::Vector2i& MousePos) override;
};


struct Map : BaseStruct {
    BaseElem BG;
    BaseElem Shop;
    BaseElem Chat;
    BaseElem Pause;
    Money Money;
    std::unordered_map<std::string, std::vector<BaseElem*>> BoughtItems;
    BaseElem* IsMove;
    int dx;
    int dy;

    Map();
    ~Map();
    std::string CheckBoundaries(sf::Vector2i& MousePos) override;
    void Draw(sf::RenderWindow& window, BaseElem& player);
    void CheckOverlap();
};


struct Shop : BaseStruct {
    BaseElem BG;
    BaseElem Close;
    BaseElem Frame;
    std::unordered_map<std::string, BaseElem*> Items;
    Map* MapPtr;

    Shop();
    explicit Shop(Map* map_ptr);
    ~Shop();
    void Draw(sf::RenderWindow& window);
    std::string CheckBoundaries(sf::Vector2i& MousePos) override;
    void ChangeColor(sf::RenderWindow& window, sf::Vector2i& MousePos);
};


struct Chat : BaseStruct {
    BaseElem Close;

    Chat();
    ~Chat();
    void Draw(sf::RenderWindow& window) const;
    std::string CheckBoundaries(sf::Vector2i& MousePos) override;
};


#endif //FERMA_BASESTRUCT_H
