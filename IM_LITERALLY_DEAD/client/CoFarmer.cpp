#include "CoFarmer.h"


CoFarmer::CoFarmer(int id, sf::Vector2f position, std::string name) : m_health(100), m_id(id), m_name("default") {
	if (!pTexture.loadFromFile("C:/Users/mi/labs_cpp/networking_sfml/Client/Media/player.png"))
		std::cout << "Error loading player.png" << std::endl;
	this->setTexture(pTexture);
	this->setPosition(position);
	this->setName(name);
}


CoFarmer::~CoFarmer() {}
