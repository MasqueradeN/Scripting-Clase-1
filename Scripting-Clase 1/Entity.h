#pragma once
class Entity
{
protected:
	sf::RectangleShape _rect;
	sf::Sprite _sprite;

public:
	Entity();
	~Entity();

	float moveSpeed;
	float posX;
	float posY;

	void InitSprite(sf::Texture& _texture);
	void InitMovement();
	void InitHitBox();

	virtual void SetPosition(const float _x, const float _y);
	virtual void Move(const float x, const float y, const float& dt);
	virtual void Update(const float& dt);

	void Render(sf::RenderTarget* _target);
};

