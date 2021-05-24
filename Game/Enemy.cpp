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

void Enemy::update(std::vector<Object*>& solid, Player* p, std::vector <Bullet*>& bullets, float elapsed_time) {
	active_melee_weapon->update(elapsed_time, this);

	immortal_timer = std::max(immortal_timer - elapsed_time, float(0));
	if (agression == DANGEROUS)
	{
		fire_attack_timer = std::max(fire_attack_timer - elapsed_time, float(0));
		if (fire_attack_timer == 0. and p!= nullptr) {
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