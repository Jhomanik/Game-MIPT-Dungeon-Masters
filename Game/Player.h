#pragma once
#include "Mob.h"
class Player:public Mob
{
public:
	//���� ������ ������ ����������� � ����� update �������� ���������
	void input();
	//������������
	Player();
	Player(float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	Player(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
};

