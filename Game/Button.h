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
	std::string f_src;
	std::string t_src;
	button_state state = UNSELECTED;
	sf::Color selected_color = sf::Color::Red;
	sf::Color unselected_color = sf::Color::White;
	sf::Color pressed_color = sf::Color::Green;
public:

	Button(std::string font_src, std::string text) {
		if (!font.loadFromFile(font_src))
		{
			std::cout << "error font" << std::endl;
		}
		f_src = font_src;
		t_src = text;
		button_text.setFont(font);
		button_text.setString(text);
	}
	void MarkButton(bool is_done) {
		if(is_done)
			button_text.setStyle(sf::Text::Underlined);
		else
			button_text.setStyle(sf::Text::Bold);
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
	void SetUnselelectedColor(sf::Color c) {
		unselected_color = c;

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
	Button* copy() {
		Button* b = new Button(t_src, f_src);
		return b;
	}

};
