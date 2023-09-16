#include "pch.h"
#include "AgresiveEnemy.h"

AgresiveEnemy::AgresiveEnemy(sf::Texture& _texture, const float x, const float y)
{
	InitSprite(_texture);
	_sprite.setScale(0.25f, 0.25f);
	SetPosition(x, y);
	this->posX = x;
	this->posY = y;
}

AgresiveEnemy::~AgresiveEnemy()
{
}

void AgresiveEnemy::NearPlayer(float px, float py, const float& dt, float _speed)
{
	this->Move(0, 0, 0);

	if (this->posX < px/3.5)
	{
		this->Move(_speed, 0, dt);
	}
	else if (this->posX >= px/3.5 - 10)
	{
		this->Move(0, 0, dt);
	}

	if (this->posX > px/3.5)
	{
		this->Move(-_speed, 0, dt);
	}
	else if (this->posX >= px/3.5 + 10)
	{
		this->Move(0, 0, dt);
	}

	if (this->posY < py/3.5)
	{
		this->Move(0, _speed, dt);
	}
	else if (this->posY >= py/3.5 - 10)
	{
		this->Move(0, 0, dt);
	}

	if (this->posY > py/3.5)
	{
		this->Move(0, -_speed, dt);
	}
	else if (this->posY >= py/3.5 + 10)
	{
		this->Move(0, 0, dt);
	}
}

void AgresiveEnemy::Update(const float& dt)
{
}
