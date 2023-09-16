#include "pch.h"
#include "GUI.h"

GUI::Button::Button(float _x, float _y, float _width, float _height, sf::Font* _font, std::string _text, unsigned _fontSize, sf::Color _idleTextColor, sf::Color _hoverTextColor, sf::Color _pressTextColor, sf::Color _idleButtonColor, sf::Color _hoverButtonColor, sf::Color _pressColor, short unsigned id)
{
	buttonState = BTN_IDLE;
	this->id = id;

	rectButton.setPosition(_x, _y);
	rectButton.setSize(sf::Vector2f(_width, _height));

	text.setPosition(rectButton.getPosition().x + (rectButton.getGlobalBounds().width/2) - text.getGlobalBounds().width/2, rectButton.getPosition().y + (text.getGlobalBounds().height/2) - text.getGlobalBounds().height/2);
	
	this->idleButtonColor = _idleButtonColor;
	this->hoverButtonColor = _hoverButtonColor;
	this->pressButtonColor = _pressColor;

	this->idleTextColor = _idleTextColor;
	this->hoverTextColor = _hoverTextColor;
	this->pressTextColor = _pressTextColor;

	this->font = _font;

	text.setFont(*font);
	text.setString(_text);
	text.setFillColor(idleTextColor);
	text.setCharacterSize(_fontSize);

	rectButton.setFillColor(idleButtonColor);
}

GUI::Button::~Button()
{
}

const std::string GUI::Button::GetText()
{
	return this->text.getString();
}

const short unsigned& GUI::Button::GetID()
{
	return 0;
}

void GUI::Button::SetText(const std::string text)
{

}

void GUI::Button::SetID(const short unsigned id)
{

}

void GUI::Button::Update(const sf::Vector2f mousePos)
{
	buttonState = BTN_IDLE;
	if (rectButton.getGlobalBounds().contains(mousePos))
	{
		buttonState = BTN_HOVER;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			buttonState = BTN_PRESS;
		}
	}

	switch (buttonState)
	{
	case BTN_IDLE:
		rectButton.setFillColor(idleButtonColor);
		text.setFillColor(idleTextColor);
		break;
	case BTN_HOVER:
		rectButton.setFillColor(hoverButtonColor);
		text.setFillColor(hoverTextColor);
		break;
	case BTN_PRESS:
		rectButton.setFillColor(pressButtonColor);
		text.setFillColor(pressTextColor);
		break;
	default:
		rectButton.setFillColor(idleButtonColor);
		text.setFillColor(sf::Color::Red);
		break;
	}
}

void GUI::Button::Render(sf::RenderTarget* _target)
{
	_target->draw(rectButton);
	_target->draw(text);
}

const bool GUI::Button::GetButtonPress()
{
	if (buttonState == BTN_PRESS)
	{
		return true;
	}
	return false;
}
