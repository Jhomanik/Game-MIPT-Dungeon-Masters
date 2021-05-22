#include "Bullet.h"
Bullet::Bullet(float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect) :Object(left, top, w, h, o_name, o_type, sprite_src, frameRect){}
Bullet::Bullet(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect) : Object(pos, size, o_name, o_type, sprite_src, frameRect){}
void Bullet::SetSpeed(float speed) {
	bul_speed = speed;
}
void Bullet::SetDiraction(sf::Vector2f dir) {
	bul_dir = dir;
}
void Bullet::draw(sf::RenderWindow* window) {
	if (!is_destroy)
	{
		window->draw(sprite);
	}
}

void Bullet::update(std::vector <Object*> solid, Player* p, float elapsed_time) {
	CheckCollision(solid, p);
	if (is_destroy) {
			
	}
	else {
		
		position += (bul_dir * bul_speed*elapsed_time);
		sprite.setPosition(position);
	}
}
bool Bullet::GetState() {
	return is_destroy;
}

Bullet* Bullet::copy() {
	Bullet* b = new Bullet(position, size, name, type, spr_source, frame_rect);
	b->SetPosition(position);
	b->SetDiraction(bul_dir);
	return b;
}