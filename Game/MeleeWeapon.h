#pragma once
#include "Basic.h"
#include "Object.h"
#include <SFML/Graphics.hpp>


typedef enum {
	ATTACK,
	COOLDOWN,
	READY
} p_attack_state;
class MeleeWeapon:public Object {
private:
	//Параметры атаки
	bool is_pressed_attack = false;
	p_attack_state p_attack = READY;
	float cooldown_time = 1000; 
	float attack_time = 10;
	float cooldown_timer = 0;
	float attack_timer = 0;
	float attack_rad = 30;
	float attack_damage = 10;
	float recoil_power = 10;
	sf::FloatRect attack_rect;

	//У игрока
	bool is_with_mob = false;
	bool is_hands = true;

	
	void CheckAttack();
public:
	
	MeleeWeapon();
	MeleeWeapon(float cool_time, float a_time, float a_rad, float a_damage, float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	MeleeWeapon(float cool_time, float a_time, float a_rad, float a_damage, sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	

	void SetAttackTimer(float time);
	void SetMeleeWeapon(float cool_time, float a_time, float a_rad, float a_damage);
	void SetRecoil(float recoil);

	p_attack_state GetState();
	float GetRad();
	float GetDamage();
	float GetCooldown();
	float GetCooldownTime();
	bool GetIsHands();
	bool GetWithMob();
	float GetRecoil();

	MeleeWeapon* copy();
	void ChangeIsHands();
	void DisconnectWithMob();
	void ConnectWithMob();

	void input();
	void draw(sf::RenderWindow* window);
	template <class T>
	void update(float elapsed_time, T* mob) {
		CheckAttack();
		if (p_attack == COOLDOWN) {
			cooldown_timer = std::max(float(0), cooldown_timer - elapsed_time);
		}
		if (p_attack == ATTACK) {
			attack_timer = std::max(float(0), attack_timer - elapsed_time);
		}
		if (is_with_mob) {
			if (is_hands)
				position = mob->GetPos() + sf::Vector2f(mob->GetSize().x/2 + 10, 0);
			else
				position = mob->GetPos();
			sprite.setPosition(position);
		}
	}
	
};

