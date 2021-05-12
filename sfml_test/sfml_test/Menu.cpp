#include "Menu.h"
#include<iostream>


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Fonts\\CyrilicOld.TTF"))
	{
		std::cout << "error font" << std::endl;
	}

	menu[0].setFont(font);                                                                       //Задаем параметры для первой кнопки
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);                                                                       //Аналогично для второй
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Close game");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));


	if (!texture.loadFromFile("images\\carpet.jpg")) {											//Задаем задний фон
		std::cout << "error texture" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setColor(sf::Color(255, 255, 255));
	sprite.setPosition(60, -30);

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw_menu(sf::RenderWindow &window)						//Рисуем фон и кнопки
{
	window.draw(sprite);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);	
	}
}


void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}



