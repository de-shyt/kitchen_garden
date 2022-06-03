#include "Player.h"


Player::Player() : m_health(100), m_id(-1) {
	pTexture.loadFromFile("C:/Users/mi/labs_cpp/networking_sfml/Client/Media/player.png");
	this->setTexture(pTexture);
}

Player::~Player() {}
