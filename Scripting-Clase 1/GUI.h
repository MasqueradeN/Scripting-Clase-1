#pragma once

enum BUTTONSTATES
{
	BTN_IDLE = 0,
	BTN_HOVER,
	BTN_PRESS
};

namespace GUI
{
	class Button
	{
	private:
		short unsigned buttonState;
		short unsigned id;

		sf::RectangleShape rectButton;
		sf::Text text;
		sf::Font* font;

		sf::Color idleButtonColor;
		sf::Color hoverButtonColor;
		sf::Color pressButtonColor;

		sf::Color idleTextColor;
		sf::Color hoverTextColor;
		sf::Color pressTextColor;

	public:
		Button(float _x, float _y, float _width, float _height, sf::Font* _font, std::string _text, unsigned _fontSize, sf::Color _idleTextColor, sf::Color _hoverTextColor, sf::Color _pressTextColor, sf::Color _idleButtonColor, sf::Color _hoverButtonColor, sf::Color _pressColor, short unsigned id = -1);

		virtual ~Button();

		const std::string GetText();
		const short unsigned& GetID();

		void SetText(const std::string text);
		void SetID(const short unsigned id);
		void Update(const sf::Vector2f mousePos);
		void Render(sf::RenderTarget* _target);

		const bool GetButtonPress();
	};
}

