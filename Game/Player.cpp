#include "Player.h"


Player::Player() :Mob() { ; }
Player::Player(float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect) : Mob(left, top, w, h, o_name, o_type, sprite_src, frameRect) { ; }
Player::Player(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect) : Mob(pos, size, o_name, o_type, sprite_src, frameRect) { ; }
void Player::input() {
	bool is_pressed = 0;
	//перенести это в метод Mob,а тут чисто распределение кому считывать input меню или игроку


	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
		m_dir = LEFT;
		is_pressed = 1;

	}

	if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
		m_dir = RIGHT;
		is_pressed = 1;
	}

	if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
		m_dir = UP;
		is_pressed = 1;
	}

	if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
		m_dir = DOWN;
		is_pressed = 1;
	}
	if (!is_pressed) {
		m_dir = STOP;
	}
}
