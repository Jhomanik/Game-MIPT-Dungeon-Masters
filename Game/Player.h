#pragma once
#include "Mob.h"


class Player:public Mob
{
private:
	
	

public:
	
	//¬вод игрока мен€ет направление и потом update измен€ет положение
	void input();
	// онструкторы
	Player();
	Player(float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	Player(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);

	Player* copy();

	template <class T>
	void update(std::vector <Object*>& solid, std::vector <T*>& enemies,std::vector<MeleeWeapon*> m_weapons, float elapsed_time) {
		//»зменение направлени€ в зависимости от движени€ 
		
		immortal_timer = std::max(immortal_timer - elapsed_time, float(0));
		
		switch (mweapon_state)
		{
		case SWAP:
			SwapMeleeWeapon();
			mweapon_state = NOTHING;
			break;
		case DROP:
			DropMeleeWeapon();
			mweapon_state = NOTHING;
			break;
		case TAKE:
		{
			MeleeWeapon* w = TakeItem(m_weapons);
			if (w != nullptr ) {
				if (m_weapon != nullptr) {
					m_weapon->DisconnectWithMob();
				}
				SetMeleeWeapon(w);
				
			}
			mweapon_state = NOTHING;
		}
			break;

		default:
			break;
		}
		
		attack(enemies);
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

		active_melee_weapon->update(elapsed_time, this);
		if (m_weapon != nullptr and active_melee_weapon != m_weapon) {
			m_weapon->update(elapsed_time, this);
		}
		if (hands != active_melee_weapon) {
			hands->update(elapsed_time, this);
		}
		

	}
	

	
	
};

