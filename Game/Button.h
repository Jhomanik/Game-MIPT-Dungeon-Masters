#pragma once
#include "SFMl/Graphics.hpp"
#include <iostream>
typedef enum {
	PRESSED,
	SELECTED,
	UNSELECTED
} button_state;
class Button
{
protected:
	sf::Font font;
	sf::Text button_text;
	sf::Color current_color = unselected_color;
	sf::Vector2f position;
	sf::Vector2f scale;
	button_state state = UNSELECTED;
	sf::Color selected_color = sf::Color::Red;
	sf::Color unselected_color = sf::Color::White;
	sf::Color pressed_color = sf::Color::Red;
public:

	Button(std::string font_src, std::string text) {
		if (!font.loadFromFile(font_src))
		{
			std::cout << "error font" << std::endl;
		}
		button_text.setFont(font);
		button_text.setString(text);
	}
	void set_params(sf::Vector2f pos, sf::Vector2f sc) {
		position = pos;
		scale = sc;
		button_text.setPosition(pos);
		button_text.setScale(scale);
	}
	void draw(sf::RenderWindow& window) {
		sf::RectangleShape shade = sf::RectangleShape(sf::Vector2f(button_text.getGlobalBounds().width + 70, button_text.getGlobalBounds().height + 25));
		shade.setPosition(position - sf::Vector2f(25,5) );
		shade.setFillColor(sf::Color::Black);
		window.draw(shade);
		button_text.setFillColor(current_color);
		window.draw(button_text);


	}
	void SelectButton() {
		state = SELECTED;
	}
	void UnselectButton() {
		state = UNSELECTED;
	}
	void PressButton() {
		state = PRESSED;
	}
	sf::FloatRect GetText() {
		return button_text.getGlobalBounds();
	}
	sf::Vector2f GetScale() {
		return scale;
	}
	void update(bool& is_menu) {
		switch (state)
		{
		case SELECTED:
			current_color = selected_color;
			break;
		case UNSELECTED:
			current_color = unselected_color;
			break;
		case PRESSED:
		{
			if (is_menu)
				is_menu = false;
			else
				is_menu = true;
			state = UNSELECTED;
			break;
		}
		
		default:
			break;
		}
	}
};



