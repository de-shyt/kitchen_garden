#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Enemy : public sf::Sprite
{
public:
	Enemy(int id, sf::Vector2f position, std::string name);
	~Enemy();

	void setID(int id){ m_id = id; }
	int getID(){ return m_id; }

	void setName(std::string name){ m_name = name; }
	std::string getName(){ return m_name; }

	void setDirection(sf::Vector2f direction) { m_direction = direction; }
	sf::Vector2f getDirection(){ return m_direction; }
private:
	sf::Texture pTexture;
	int m_id;
	std::string m_name;
	sf::Vector2f m_direction;
};

