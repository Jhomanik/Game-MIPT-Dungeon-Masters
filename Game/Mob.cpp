#include "Mob.h"

Mob::Mob():Object(){
	//Перчаточка
	
	glove_image.loadFromFile("images\\glove.png");
	glove_texture.loadFromImage(glove_image);
	glove.setTexture(glove_texture);
	glove.scale(0.5, 0.5);
	


	m_health = 100.;
	
	m_dir = STOP;

	is_life = true;
	active_melee_weapon = new MeleeWeapon;
	
	image.loadFromFile("images\\default.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

Mob::Mob(float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect):Object(left,top,w,h,o_name,o_type, sprite_src, frameRect) {
	m_health = 100;

	m_dir = STOP;
	hands = new MeleeWeapon;
	m_weapon = nullptr;
	active_melee_weapon = hands;
	is_life = true;
	
	glove_image.loadFromFile("images\\glove.png");
	glove_texture.loadFromImage(glove_image);
	glove.setTexture(glove_texture);
	glove.scale(0.5, 0.5);
	
	
}

Mob::Mob(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect) :Object(pos,size, o_name, o_type, sprite_src, frameRect) {
	m_health = 100;

	m_dir = STOP;
	is_life = true;
	hands = new MeleeWeapon;
	m_weapon = nullptr;
	active_melee_weapon = hands;

	
	glove_image.loadFromFile("images\\glove.png");
	glove_texture.loadFromImage(glove_image);
	glove.setTexture(glove_texture);
	glove.scale(0.5, 0.5);
	
	
	
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
void Mob::SetLife(bool life) {
	is_life = life;
}
void Mob::SetHealth(float health) {
	m_health = health;
}
void Mob::SetDiraction(m_dir_state dir) {
	m_dir = dir;
}
void Mob::SetMobParams(float health, float speed) {
	m_health = health;
	m_speed = speed;
}


bool Mob::GetIsLife() {
	return is_life;
}
float Mob::GetHealth() {
	return m_health;
}
void Mob::TakeDamage(float damage, sf::Vector2f damage_dir, float attack_duration) {
	if (immortal_timer == 0.)
	{
		recoil_timer = attack_duration;
		recoil_dir = position + sf::Vector2f(size.x / 2, size.y / 2) - damage_dir;
		float l = sqrt(recoil_dir.x * recoil_dir.x + recoil_dir.y * recoil_dir.y);
		recoil_dir.x /= l;
		recoil_dir.y /= l;


		m_health = std::max(m_health -= damage, float(0));
		immortal_timer = 1000;
		if (m_health == 0.) {
			is_life = false;
		}
	}
}
void Mob::CheckCollisionsWithMap(std::vector<Object*>&solid, float Dx, float Dy) {
	for (auto o : solid) {
		
		if (GetRect().intersects(o->GetRect())) {
			float x = position.x, y = position.y;
			if (Dy > 0) {
				y = o->GetPos().y - size.y; 
				if (recoil_timer != 0.) { 
					recoil_dir.y = -recoil_dir.y;
					recoil_timer /= 2;
				} 
			}
			if (Dy < 0) {
				y = o->GetPos().y + o->GetSize().y;
				if (recoil_timer != 0.)
				{
					recoil_dir.y  = -recoil_dir.y;
					recoil_timer /= 2;
				}
			}
			if (Dx > 0) {
				x = o->GetPos().x - size.x;
				if (recoil_timer != 0.)
				{
					recoil_dir.x = - recoil_dir.x;
					recoil_timer /= 2;
				}
			}
			if (Dx < 0) {
				x = o->GetPos().x + o->GetSize().x; 
				if (recoil_timer != 0.) {
					recoil_dir.x  = -recoil_dir.x;
					recoil_timer /= 2;
				}
			}
			position = sf::Vector2f(x, y);
			
		}
	}
}

void Mob::draw(sf::RenderWindow* window) {
	if (m_weapon != nullptr and active_melee_weapon != m_weapon) {
		m_weapon->draw(window);
	}
	window->draw(sprite);
	active_melee_weapon->draw(window);
	glove.setPosition(position + sf::Vector2f(size.x/2+10,size.y/2));
	window->draw(glove);

	Font font;//шрифт 
	font.loadFromFile("fonts\\CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
	Text text("", font, 20);
	text.setFillColor(sf::Color::Red);
	std::string str = name + "\nhp:" +std::to_string(int(m_health)) + "\n";
	switch (active_melee_weapon->GetState())
	{
	case ATTACK:
		str += "attack";
		break;
	case COOLDOWN:
		str += "cd: " + std::to_string(int(active_melee_weapon->GetCooldown() / 100));
		break;
	case READY:
		str += "ready";
		break;
	default:

		break;
	}
	text.setString(str);
	text.setStyle(sf::Text::Bold);
	text.setPosition(position-sf::Vector2f(0,50));
	window->draw(text);
}
sf::RectangleShape Mob::GetAttackShape() {
	if (active_melee_weapon->GetState() == ATTACK)
	{
		sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(attack_rect.width, attack_rect.width));
		rect.setPosition(sf::Vector2f(attack_rect.left, attack_rect.top));
		rect.setFillColor(Color::Red);
		return rect;
	}
	else
		return sf::RectangleShape();
	
}
void Mob::SwapMeleeWeapon() {
	if (m_weapon != nullptr and active_melee_weapon == hands) {
		active_melee_weapon = m_weapon;
		m_weapon->ChangeIsHands();
		return;
	}
	if (m_weapon != nullptr and active_melee_weapon == m_weapon ) {
		active_melee_weapon = hands;
		m_weapon->ChangeIsHands();
		return;
	}
}
void Mob::SetMeleeWeapon(MeleeWeapon* melee_weapon) {
	if (m_weapon != nullptr) {
		m_weapon->DisconnectWithMob();
	}
	m_weapon = melee_weapon;
	active_melee_weapon = melee_weapon;
	melee_weapon->ConnectWithMob();
}
void Mob::DropMeleeWeapon() {
	if (active_melee_weapon != hands) {
		active_melee_weapon = hands;
		m_weapon->DisconnectWithMob();
		m_weapon = nullptr;
	}

}
void Mob::Kill() {
	if (m_weapon != nullptr) {
		m_weapon->DisconnectWithMob();
	}
}

