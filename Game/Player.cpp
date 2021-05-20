#include "Player.h"
#include <algorithm>

Player::Player() :Mob() { 
}
Player::Player(float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect) : Mob(left, top, w, h, o_name, o_type, sprite_src, frameRect) {
	
}
Player::Player(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect) : Mob(pos, size, o_name, o_type, sprite_src, frameRect) {
	
}
void Player::input() {
	bool is_pressed_move = 0;
	bool is_pressed_mweapon = 0;
	//перенести это в метод Mob,а тут чисто распределение кому считывать input меню или игроку
	if (Keyboard::isKeyPressed(Keyboard::F)) {
		mweapon_state = TAKE;
		is_pressed_mweapon = 1;
		
	}
	if (Keyboard::isKeyPressed(Keyboard::Q)) {

		mweapon_state = DROP;
		is_pressed_mweapon = 1;
	
	}
	if (Keyboard::isKeyPressed(Keyboard::E)) {
		mweapon_state = SWAP;
		is_pressed_mweapon = 1;
	
	}
	if (!is_pressed_mweapon) {
		mweapon_state = NOTHING;
	}
	active_melee_weapon->input();


	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
		m_dir = LEFT;
		is_pressed_move = 1;

	}

	if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
		m_dir = RIGHT;
		is_pressed_move = 1;
	}

	if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
		m_dir = UP;
		is_pressed_move = 1;
	}

	if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
		m_dir = DOWN;
		is_pressed_move = 1;
	}
	
	if (!is_pressed_move) {
		m_dir = STOP;
	}
}


Player* Player::copy() {
	Player* e = new Player(position, size, name, type, spr_source, frame_rect);
	e->SetHealth(m_health);
	if (m_weapon != nullptr)
	{
		MeleeWeapon* weapon = m_weapon->copy();
		e->SetMeleeWeapon(weapon);
	}
	return e;
}




