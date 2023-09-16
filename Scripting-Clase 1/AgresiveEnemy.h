#pragma once
#include "Entity.h"
class AgresiveEnemy :
    public Entity
{
public:
	sf::RectangleShape rect;
	sf::Texture _agEnTexture;

	AgresiveEnemy(sf::Texture& _texture, const float x, const float y);
	virtual ~AgresiveEnemy();

	void NearPlayer(float px, float py, const float& dt, float _speed);

	void Update(const float& dt);
};

