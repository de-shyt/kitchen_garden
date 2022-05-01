#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.h"

class Player {
public:
    float x, y, w, h, dx, dy, speed = 0;
    int dir = 0;
    sf::String File;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

    Player(sf::String F, float X, float Y, float recLeft, float recTop, float W, float H) : x(X), y(Y), w(W), h(H), dx(0), dy(0), File(F) {
        image.loadFromFile("images/" + File);
        image.createMaskFromColor(sf::Color(41, 33, 59));
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(recLeft, recTop, w, h));
    }

    void update(float time) {
        switch(dir) {
            case 0: dx = speed; dy = 0; break;
            case 1: dx = -speed; dy = 0; break;
            case 2: dx = 0; dy = speed; break;
            case 3: dx = 0; dy = -speed; break;
        }

        x += dx * time;
        y += dy * time;

        speed = 0;
        sprite.setPosition(x, y);
    }

    void go_left(float &CurrentFrame, float &time) {
        dir = 1; speed = 0.1;
        CurrentFrame += 0.005 * time;
        if (CurrentFrame > 4) CurrentFrame -= 4;
        sprite.setTextureRect(sf::IntRect(64 * int(CurrentFrame), 96, 64, 96));
    }

    void go_right(float &CurrentFrame, float &time) {
        dir = 0; speed = 0.1;
        CurrentFrame += 0.005 * time;
        if (CurrentFrame > 4) CurrentFrame -= 4;
        sprite.setTextureRect(sf::IntRect(64 * int(CurrentFrame), 192, 64, 96));
    }

    void go_up(float &CurrentFrame, float &time) {
        dir = 3; speed = 0.1;
        CurrentFrame += 0.005 * time;
        if (CurrentFrame > 4) CurrentFrame -= 4;
        sprite.setTextureRect(sf::IntRect(64 * int(CurrentFrame), 288, 64, 96));
    }
    void go_down(float &CurrentFrame, float &time) {
        dir = 2; speed = 0.1;
        CurrentFrame += 0.005 * time;
        if (CurrentFrame > 4) CurrentFrame -= 4;
        sprite.setTextureRect(sf::IntRect(64 * int(CurrentFrame), 0, 64, 96));
    }
};
