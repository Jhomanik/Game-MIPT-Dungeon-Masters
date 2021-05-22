#include "MeleeWeapon.h"

MeleeWeapon::MeleeWeapon() :Object() { is_with_mob = true;  is_hands = true; }
MeleeWeapon::MeleeWeapon(float cool_time, float a_time, float a_rad, float a_damage, float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect) : Object(left, top, w, h, o_name, o_type, sprite_src, frameRect) {
	attack_time = a_time;
	attack_damage = a_damage;
	cooldown_time = cool_time;
	attack_rad = a_rad;
	float cooldown_timer = 0;
	float attack_timer = 0;
	bool is_pressed_attack = false;
	p_attack_state p_attack = READY;

}
MeleeWeapon::MeleeWeapon(float cool_time, float a_time, float a_rad, float a_damage, sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect) : Object(pos, size, o_name, o_type, sprite_src, frameRect) {
	attack_time = a_time;
	attack_damage = a_damage;
	cooldown_time = cool_time;
	attack_rad = a_rad;
	float cooldown_timer = 0;
	float attack_timer = 0;
	bool is_pressed_attack = false;
	p_attack_state p_attack = READY;
}
MeleeWeapon* MeleeWeapon::copy() {
	MeleeWeapon* pointer = new MeleeWeapon(cooldown_time, attack_time, attack_rad, attack_damage, position, size, name, type, spr_source, frame_rect);
	pointer->is_with_mob = is_with_mob;
	pointer->is_hands = is_hands;
	return pointer;
}

void MeleeWeapon::SetMeleeWeapon(float cool_time, float a_time, float a_rad, float a_damage) {
	attack_time = a_time;
	attack_damage = a_damage;
	cooldown_time = cool_time;
	attack_rad = a_rad;
	float cooldown_timer = 0;
	float attack_timer = 0;
	bool is_pressed_attack = false;
	p_attack_state p_attack = READY;

}
void MeleeWeapon::CheckAttack() {
	if (is_pressed_attack && p_attack == READY) {
		p_attack = ATTACK;
		attack_timer = attack_time;
	}
	if (attack_timer == 0. && p_attack == ATTACK) {
		p_attack = COOLDOWN;
		cooldown_timer = cooldown_time;
	}
	if (cooldown_timer == 0. && p_attack == COOLDOWN) {
		p_attack = READY;
	}
}
void MeleeWeapon::SetRecoil(float recoil) {
	recoil_power = recoil;
}
float MeleeWeapon::GetRecoil() {
	return recoil_power;
}
void MeleeWeapon::input() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::G) || sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		is_pressed_attack = true;
	}
	else {
		is_pressed_attack = false;
	}
}


p_attack_state MeleeWeapon::GetState() {
	return p_attack;
}
float MeleeWeapon::GetRad() {
	return attack_rad;
}
float MeleeWeapon::GetDamage() {
	return attack_damage;
}
float MeleeWeapon::GetCooldown() {
	return cooldown_timer;
}

void MeleeWeapon::SetAttackTimer(float time) {
	this->attack_timer = time;
}

void MeleeWeapon::draw(sf::RenderWindow* window) {
	
	window->draw(sprite);
}
bool MeleeWeapon::GetWithMob() {
	return is_with_mob;
}
bool MeleeWeapon::GetIsHands() {
	return is_hands;
}
void MeleeWeapon::ChangeIsHands() {
	is_hands = (is_hands)?  false : true ;
}
void MeleeWeapon::ConnectWithMob() {
	if (!is_with_mob) {
		
		is_with_mob = true;
		is_hands = true;
	}
}
void MeleeWeapon::DisconnectWithMob() {
	if (is_with_mob and attack_timer == 0.) {
		
		is_with_mob = false;
		is_hands = false;
	}
}