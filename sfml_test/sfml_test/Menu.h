#pragma once
#include "SFMl/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 2

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw_menu(sf::RenderWindow &window);   //Отрисовка меню
	void MoveUp();                              //Отвечает за смену кнопки при нажатии вверх  
	void MoveDown();                            //Аналогично для низа
	int getPressedItem() { return selectedItemIndex; } //Вспомогательная фунция для счетчика кнопок

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Texture texture;
	sf::Sprite sprite;
};


