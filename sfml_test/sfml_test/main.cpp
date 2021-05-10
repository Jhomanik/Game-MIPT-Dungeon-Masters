#include"SFML/Graphics.hpp"
#include <iostream>
#include "Menu.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(700, 400), "menu test");
	Menu menu(window.getSize().x, window.getSize().y);
	
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.getPressedItem())
					{
					case 0:
						std::cout << "Play" << std::endl;
						break;
					case 1:
						window.close();
						break;
					default:
						break;
					}

				default:
					break;
				}
				break;

			default:
				break;
			}
		}

		window.clear();
		menu.draw_menu(window);
		window.display();
	}

	//system("pause");
	return 0;
}
