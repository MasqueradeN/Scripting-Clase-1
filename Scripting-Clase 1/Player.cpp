 #include "pch.h"
#include "Player.h"

Player::Player(sf::Texture& _texture, const float x, const float y)
{
	InitSprite(_texture);
	//_sprite.setScale();
	SetPosition(x, y);
	this->posX = x;
	this->posY = y;
}

Player::~Player()
{

}

void Player::Update(const float& dt)
{

}