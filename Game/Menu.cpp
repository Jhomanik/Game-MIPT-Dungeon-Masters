#include "Menu.h"
#include<iostream>


Menu::Menu(float width, float height, std::vector <Button*>& buttons)
{

	menu = buttons;
	MAX_NUMBER_OF_ITEMS = buttons.size();
	for (int i = 0; i < buttons.size(); i++) {
		sf::FloatRect text_rect = menu[i]->GetText();

		menu[i]->set_params(sf::Vector2f(width / 2  - text_rect.width/2*2, height / (MAX_NUMBER_OF_ITEMS + 1) * (i + 1)), sf::Vector2f(2, 2));
		menu[i]->UnselectButton();
	}

	if (!texture.loadFromFile("images\\main_menu_background.jpg")) {											//Çàäàåì çàäíèé ôîí
		std::cout << "error texture" << std::endl;
	}
	if (!font.loadFromFile("Fonts\\CyrilicOld.TTF")) {											//Çàäàåì çàäíèé ôîí
		std::cout << "error font" << std::endl;
	}

	sprite.setTexture(texture);
	sprite.setColor(sf::Color(255, 255, 255));
	sprite.setPosition(0, 0);
	menu_width = width;
	menu_height = height;
	selectedItemIndex = 0;
	menu[selectedItemIndex]->SelectButton();
}


void Menu::draw(sf::RenderWindow& window)						
{
	window.draw(sprite);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		menu[i]->draw(window);
	}
	window.draw(title);
}


void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex]->UnselectButton();
		selectedItemIndex--;
		menu[selectedItemIndex]->SelectButton();
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex]->UnselectButton();
		selectedItemIndex++;
		menu[selectedItemIndex]->SelectButton();
	}
}
void Menu::input() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		MoveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		MoveDown();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		menu[selectedItemIndex]->PressButton();
		if (selectedItemIndex != 0)
		{
			selectedItemIndex = 0;
			menu[selectedItemIndex]->SelectButton();
			is_first_pressed = false;
		}
		else {
			is_first_pressed = true;
		}
	}
}

void Menu::SetSprite(std::string& src) {
	src_image = src;
	if (!texture.loadFromFile(src)) {											//Çàäàåì çàäíèé ôîí
		std::cout << "error texture" << std::endl;
	}
	sprite.setTexture(texture);

}
void Menu::SetTitle(std::string& title_src) {
	title_source = title_src;
	title.setFont(font);
	title.setString(title_src);


	title.setPosition(sf::Vector2f(menu_width / 2 - title.getGlobalBounds().width/2*3,20));
	title.setScale(3, 2.5);
	title.setFillColor(sf::Color::White);
}