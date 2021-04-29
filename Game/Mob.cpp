#include "Mob.h"

Mob::Mob():Object(){
	

	m_health = 100.;
	m_speed = 0.5;
	m_dir = STOP;
	image.loadFromFile("images\\default.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

Mob::Mob(float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect):Object(left,top,w,h,o_name,o_type) {
	m_health = 100;
	m_speed = 0.5;
	m_dir = STOP;
	image.loadFromFile(sprite_src);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(frameRect);
	sprite.setPosition(position);
}

Mob::Mob(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect) :Object(pos,size, o_name, o_type) {
	m_health = 100;
	m_speed = 0.5;
	m_dir = STOP;
	
	image.loadFromFile(sprite_src);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(frameRect);
	sprite.setPosition(position);
}




void Mob::SetSprite(std::string src, sf::IntRect frameRect) {
	image.loadFromFile(src);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(frameRect);
	size = sf::Vector2f(frameRect.height, frameRect.width);
}

void Mob::SetSpeed(float speed) {
	m_speed = speed;
}
void Mob::SetLife(float health) {
	m_health = health;
}
void Mob::SetDiraction(m_state dir) {
	m_dir = dir;
}
void Mob::SetMobParams(float health, float speed) {
	m_health = health;
	m_speed = speed;
}

void Mob::draw(sf::RenderWindow* window) {
	sprite.setPosition(position);
	window->draw(sprite);
}

void Mob::CheckCollisionsWithMap(std::vector<Object*>&solid, float Dx, float Dy) {
	for (auto o : solid) {
		
		if (GetRect().intersects(o->GetRect())) {
			float x = position.x, y = position.y;
			if (Dy > 0) { y = o->GetPos().y - size.y; }
			if (Dy < 0) { y = o->GetPos().y + o->GetSize().y;    }
			if (Dx > 0) { x = o->GetPos().x - size.x; }
			if (Dx < 0) { x = o->GetPos().x + o->GetSize().x;}
			position = sf::Vector2f(x, y);
			
		}
	}

}
void Mob::update(std::vector <Object*> & solid, float elapsed_time) {
	//»зменение направлени€ в зависимости от движени€ 
	float dx = 0, dy = 0;
	switch (m_dir)
	{
	case UP:
		dy = -m_speed;
		break;
	case DOWN:
		dy = m_speed;
		break;
	case LEFT:
		dx = -m_speed;
		break;
	case RIGHT:
		dx = m_speed;
		break;
	default:

		break;
	}
	position.x += dx * elapsed_time;
	CheckCollisionsWithMap(solid,dx, 0 );
	position.y += dy * elapsed_time;
	CheckCollisionsWithMap(solid, 0, dy);
	sprite.setPosition(position.x, position.y);
}



