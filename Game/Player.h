#pragma once
#include "Mob.h"
class Player:public Mob
{
public:
	//Ввод игрока меняет направление и потом update изменяет положение
	void input();
	//Конструкторы
	Player();
	Player(float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	Player(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
};

