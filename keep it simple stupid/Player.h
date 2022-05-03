#ifndef DRAFT_PLAYER_H
#define DRAFT_PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>

enum class Direction {Left, Right, Up, Down};


namespace custom_exceptions {
    struct unable_to_open_a_file : std::runtime_error {
        explicit unable_to_open_a_file(const std::string& name);
    };
}


struct BaseElem {
    float x = 0, y = 0, w = 0, h = 0;
    std::string FileName;
    sf::Sprite mSprite;
    sf::Texture mTexture;
    sf::Image mImage;

    BaseElem();
    explicit BaseElem(float x_, float y_, float w_, float h_, std::string&& name);
//    BaseElem& operator=(BaseElem&& Elem) noexcept;
};



struct Player : BaseElem {
    float dx = 0, dy = 0, speed = 0;
    Direction dir = Direction::Right;

    Player();
    explicit Player(float x_, float y_, float w_, float h_, float recTop, float recLeft, std::string&& name);
    void update(float time);
    void GoLeft(float &CurrentFrame, float &time);
    void GoRight(float &CurrentFrame, float &time);
    void GoUp(float &CurrentFrame, float &time);
    void GoDown(float &CurrentFrame, float &time);
};



struct BaseStruct {
    virtual std::string CheckBoundaries(sf::Vector2i& MousePos) const = 0;
};


struct Menu : BaseStruct {
    BaseElem NewGame = BaseElem(100, 30, 169, 39, "newgame.png");
    BaseElem Exit = BaseElem(100, 90, 110, 41, "exit.png");
    BaseElem Carrot = BaseElem(300, -20, 918, 950, "carrot.png");
//    Carrot.mSprite.setRotation(15);

    void Draw(sf::RenderWindow& window) const;
    void ChangeColor(sf::RenderWindow& window);
    std::string CheckBoundaries(sf::Vector2i& MousePos) const;
};


struct Map : BaseStruct {
    BaseElem BG = BaseElem(0, 0, 2048, 2048, "grassBG.png");
    BaseElem Shop = BaseElem(50, 50, 100, 100, "shop.png");
    BaseElem Chat = BaseElem(50, 200, 100, 100, "chat.png");
    BaseElem Pause = BaseElem(1770, 50, 100, 100, "pause.png");

    std::string CheckBoundaries(sf::Vector2i& MousePos) const;
    void Draw(sf::RenderWindow& window);
};


struct Shop : BaseStruct {
    BaseElem BG = BaseElem(0, 0, 2048, 2048, "shopBG.png");
    BaseElem Close = BaseElem(1770, 50, 100, 100, "close.png");
    std::vector<BaseElem> Items;

    Shop();
    ~Shop();
    void Draw(sf::RenderWindow& window) const;
    std::string CheckBoundaries(sf::Vector2i& MousePos) const;
};


struct Chat : BaseStruct {
    BaseElem Close = BaseElem(1770, 50, 100, 100, "close.png");

    Chat();
    ~Chat();
    void Draw(sf::RenderWindow& window) const;
    std::string CheckBoundaries(sf::Vector2i& MousePos) const;
};

#endif //DRAFT_PLAYER_H
