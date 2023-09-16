#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
	sf::RectangleShape rect;
	sf::Texture _plTexture;
	Player(sf::Texture& _texture, const float x, const float y);
	virtual ~Player();

	void Update(const float& dt);
};

