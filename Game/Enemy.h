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


	
	void update(std::vector<Object*>& solid, Player* p,std::vector <Bullet*>& bullets, float elapsed_time) {
		active_melee_weapon->update(elapsed_time,this);

		immortal_timer = std::max(immortal_timer - elapsed_time, float(0));
		if (agression == DANGEROUS)
		{
			fire_attack_timer = std::max(fire_attack_timer - elapsed_time, float(0));
			if (fire_attack_timer == 0.) {
				fire_attack_timer = fire_attack_time;
				sf::Vector2f p_dir = p->GetPos();
				sf::Vector2f bul_dir = p_dir - position;
				float l = sqrt(bul_dir.x * bul_dir.x + bul_dir.y * bul_dir.y);
				bul_dir /= l;
				Bullet* new_bullet = FireAttack(bul_dir);
				bullets.push_back(new_bullet);
			}
		}
		float dx = 0, dy = 0;
		switch (m_dir)
		{
		case UP:
			dy = -m_speed * elapsed_time;
			break;
		case DOWN:
			dy = m_speed * elapsed_time;
			break;
		case LEFT:
			dx = -m_speed * elapsed_time;
			break;
		case RIGHT:
			dx = m_speed * elapsed_time;
			break;
		default:

			break;
		}
		recoil_timer = std::max(recoil_timer - elapsed_time, float(0));
		recoil_timer = std::max(recoil_timer - elapsed_time, float(0));
		if (recoil_timer != 0.) {
			dx += recoil_dir.x;

		}
		position.x += dx;
		CheckCollisionsWithMap(solid, dx, 0);
		sprite.setPosition(position.x, position.y);
		if (recoil_timer != 0.) {
			dy += recoil_dir.y;

		}
		position.y += dy;
		CheckCollisionsWithMap(solid, 0, dy);
		sprite.setPosition(position.x, position.y);

	}
};

