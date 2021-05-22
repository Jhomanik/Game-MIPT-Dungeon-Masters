#include "Enemy.h"
Enemy::Enemy():Mob() {
}
Enemy::Enemy(float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect) : Mob(left, top, w, h, o_name, o_type, sprite_src, frameRect) {

}
Enemy::Enemy(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect) : Mob(pos, size, o_name, o_type, sprite_src, frameRect) {

}
void Enemy::SetAgression(agression_state agression) {
	this->agression = agression;
}
Enemy* Enemy::copy() {
	Enemy* e = new Enemy(position, size, name, type, spr_source, frame_rect);
	e->SetHealth(m_health);
	e->SetAgression(agression);
	if (m_weapon != nullptr)
	{
		MeleeWeapon* weapon = m_weapon->copy();
		e->SetMeleeWeapon(weapon);
	}
	return e;
}

Bullet* Enemy::FireAttack(sf::Vector2f direction) {
	Bullet* b = new Bullet(position, sf::Vector2f(20, 20), "fire_ball", "bullet", "images\\fireball.png", sf::IntRect(100, 165, 30, 30));
	b->SetDiraction(direction);
	return b;
}