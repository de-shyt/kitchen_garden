#ifndef FERMA_BASESTRUCT_H
#define FERMA_BASESTRUCT_H


#include "TextElem.h"
#include "BaseElem.h"
#include <unordered_map>
#include <soci/session.h>
#include <soci/transaction.h>
#include <soci/backend-loader.h>
#include <soci/connection-parameters.h>


struct BaseStruct {
    soci::session sql;

    BaseStruct();
    virtual std::string CheckBoundaries(sf::Vector2i& MousePos) = 0;
};

struct Map;

struct Menu : virtual BaseStruct {
    TextElem NewGame;
    TextElem Continue;
    TextElem Settings;
    TextElem Exit;
    BaseElem Carrot;
    Map *MapPtr;
    Player* PlayerPtr;

    explicit Menu(Map *m, Player *pm);
    void Draw(sf::RenderWindow& window) const;
    void ChangeColor(sf::RenderWindow& window);
    std::string CheckBoundaries(sf::Vector2i& MousePos) override;
};


struct Map : virtual BaseStruct {
    BaseElem BG;
    BaseElem Shop;
    BaseElem Chat;
    BaseElem Pause;
    Money Money;
    std::unordered_map<std::string, std::vector<BaseElem*>> BoughtItems;
    BaseElem* IsMove;
    std::string IsMove_Name;
    int IsMove_id;
    int dx;
    int dy;

    Map();
    ~Map();
    std::string CheckBoundaries(sf::Vector2i& MousePos) override;
    void Draw(sf::RenderWindow& window, BaseElem& player);
    void CheckOverlap();
};


struct Shop : virtual BaseStruct {
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


struct Chat : virtual BaseStruct {
    BaseElem Close;

    Chat();
    ~Chat();
    void Draw(sf::RenderWindow& window) const;
    std::string CheckBoundaries(sf::Vector2i& MousePos) override;
};


#endif //FERMA_BASESTRUCT_H
