#include "pch.h"
#include "Entity.h"

Entity::Entity()
{
	moveSpeed = 50;
}

Entity::~Entity()
{
}

void Entity::InitSprite(sf::Texture& _texture)
{
	_sprite.setTexture(_texture);
	
}

void Entity::Render(sf::RenderTarget* _target)
{
	_target->draw(_sprite);
}

void Entity::SetPosition(const float _x, const float _y)
{
	_sprite.setPosition(sf::Vector2f(_x, _y));
}

void Entity::Move(const float x, const float y, const float& dt)
{
	float xvalue = 0;
	xvalue += x * moveSpeed * dt;
	posX += x;
	float yvalue = 0;
	yvalue += y * moveSpeed * dt;
	posY += y;
	_sprite.move(sf::Vector2f(xvalue, yvalue));
}

void Entity::Update(const float& dt)
{

}
