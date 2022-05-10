#include "Player.h"
//#define FILE_LOCATION "C:/Users/NB/CLionProjects/draft1/images/"
#define FILE_LOCATION "images/"


custom_exceptions::unable_to_open_a_file::unable_to_open_a_file(const std::string& name)
        : std::runtime_error("Unable to open file '" + name + "'\n") {}



BaseElem::BaseElem() = default;


BaseElem::BaseElem(float x_, float y_, float w_, float h_, std::string &&name)
        : x(x_), y(y_), w(w_), h(h_), FileName(std::move(name))
{
    std::ifstream f(FILE_LOCATION + FileName);
    if (!f.is_open()) {
        throw custom_exceptions::unable_to_open_a_file(FileName);
    }

    mImage.loadFromFile(FILE_LOCATION + FileName);
    mTexture.loadFromImage(mImage);
    mSprite.setTexture(mTexture);
    mSprite.setPosition(x, y);

}



Player::Player() = default;


Player::Player(float x_, float y_, float w_, float h_,
               float recTop, float recLeft, std::string &&name)
        : BaseElem(x_, y_, w_, h_, std::move(name))
{
    mSprite.setTextureRect(sf::IntRect(recLeft, recTop, w, h));
}


void Player::InteractionWithMap(Map* MapPtr) {
    for (auto& it : MapPtr->BoughtItems) {
        for (auto& elem : it.second) {
            if (elem->mSprite.getGlobalBounds().intersects(sf::Rect(sf::Rect(x, y, w, h)))) {
                std::cout << "elem: " << elem->mSprite.getGlobalBounds().left << ' ' << elem->mSprite.getGlobalBounds().top << ' '
                << elem->mSprite.getGlobalBounds().width << ' ' << elem->mSprite.getGlobalBounds().height << '\n';
                std::cout << elem->x << ' ' << elem->y << ' ' << elem->w << ' ' << elem->h << "\n\n";
                std::cout << "farmer: " << mSprite.getGlobalBounds().left << ' ' << mSprite.getGlobalBounds().top << ' '
                << mSprite.getGlobalBounds().width << ' ' << mSprite.getGlobalBounds().height << '\n';
                switch(dir) {
                    case Direction::Right: {
                        x = elem->x - w;
                    } break;
                    case Direction::Left: {
                        x = elem->x + elem->w;
                    } break;
                    case Direction::Up: {
                        y = elem->y + elem->h;
                    } break;
                    case Direction::Down: {
                        y = elem->y - h;
                    } break;
                }
                std::cout << "coords: " << x << ' ' << y << "\n\n";
            }
        }
    }
}


void Player::update(float time, Map* MapPtr) {
    switch(dir) {
        case Direction::Right: {
            dx = speed, dy = 0;
        } break;
        case Direction::Left: {
            dx = -speed, dy = 0;
        } break;
        case Direction::Up: {
            dx = 0, dy = -speed;
        } break;
        case Direction::Down: {
            dx = 0, dy = speed;
        } break;
    }
    x += dx * time;
    y += dy * time;

    InteractionWithMap(MapPtr);

    speed = 0;
    mSprite.setPosition(x, y);
}


void Player::GoLeft(float &CurrentFrame, float &time) {
    dir = Direction::Left;
    speed = 0.25;
    CurrentFrame += 0.005 * time;
    if (CurrentFrame > 4) CurrentFrame -= 4;
    mSprite.setTextureRect(sf::IntRect(64 * int(CurrentFrame), 96, 64, 96));
}


void Player::GoRight(float &CurrentFrame, float &time) {
    dir = Direction::Right;
    speed = 0.25;
    CurrentFrame += 0.005 * time;
    if (CurrentFrame > 4) CurrentFrame -= 4;
    mSprite.setTextureRect(sf::IntRect(64 * int(CurrentFrame), 192, 64, 96));
}


void Player::GoUp(float &CurrentFrame, float &time) {
    dir = Direction::Up;
    speed = 0.25;
    CurrentFrame += 0.005 * time;
    if (CurrentFrame > 4) CurrentFrame -= 4;
    mSprite.setTextureRect(sf::IntRect(64 * int(CurrentFrame), 288, 64, 96));
}


void Player::GoDown(float &CurrentFrame, float &time) {
    dir = Direction::Down;
    speed = 0.25;
    CurrentFrame += 0.005 * time;
    if (CurrentFrame > 4) CurrentFrame -= 4;
    mSprite.setTextureRect(sf::IntRect(64 * int(CurrentFrame), 0, 64, 96));
}

void Player::move(float &CurrentFrame, float &time) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        GoLeft(CurrentFrame, time);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        GoRight(CurrentFrame, time);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        GoUp(CurrentFrame, time);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        GoDown(CurrentFrame, time);
}
