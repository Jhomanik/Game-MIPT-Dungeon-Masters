#pragma once
#include "Mob.h"
#include "Bullet.h"
typedef enum {
	PEACEFULL,
	DANGEROUS
} agression_state;
class Enemy:public Mob
{
private:
	float fire_attack_time = 1000;
	float fire_attack_timer = 0.;
	agression_state agression = DANGEROUS;

public:
	Enemy();
	Enemy(float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	Enemy(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	
	void SetAgression(agression_state agression);

	Enemy* copy();
	Bullet* FireAttack(sf::Vector2f direction);

	void update(std::vector<Object*>& solid, Player* p, std::vector <Bullet*>& bullets, float elapsed_time);
	
};

