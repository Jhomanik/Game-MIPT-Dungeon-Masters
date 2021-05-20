#pragma once
#include "Mob.h"

class Enemy:public Mob
{
public:
	Enemy();
	Enemy(float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	Enemy(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);

	Enemy* copy();
	template <class T>
	void update(std::vector<Object*>& solid, std::vector <T*> players, float elapsed_time) {
		active_melee_weapon->update(elapsed_time,this);

		immortal_timer = std::max(immortal_timer - elapsed_time, float(0));
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

