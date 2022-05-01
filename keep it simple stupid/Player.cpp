#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"

custom_exceptions::unable_to_open_a_file::unable_to_open_a_file(const std::string& name)
        : std::runtime_error("Unable to open file '" + name + "'\n") {}



BaseElem::BaseElem() = default;

BaseElem::BaseElem(float x_, float y_, float w_, float h_, std::string &&name)
    : x(x_), y(y_), w(w_), h(h_), FileName(std::move(name))
{
    std::ifstream f("images/" + FileName);
    if (!f.is_open()) {
        throw custom_exceptions::unable_to_open_a_file(FileName);
    }

    mImage.loadFromFile("images/" + FileName);
    mTexture.loadFromImage(mImage);
    mSprite.setTexture(mTexture);
    mSprite.setPosition(x, y);

}



Player::Player() = default;

Player::Player(float x_, float y_, float w_, float h_,
               float recTop, float recLeft, std::string &&name)
    : BaseElem(x_, y_, w_, h_, std::move(name)) {
//    mImage.createMaskFromColor(sf::Color(0,0,0));
//    mImage.createMaskFromColor(sf::Color(255,255,255));
    mSprite.setTextureRect(sf::IntRect(recLeft, recTop, w, h));
}

void Player::update(float time) {
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
    dir = Direction::Down; speed = 0.25;
    CurrentFrame += 0.005 * time;
    if (CurrentFrame > 4) CurrentFrame -= 4;
    mSprite.setTextureRect(sf::IntRect(64 * int(CurrentFrame), 0, 64, 96));
}


