#pragma once
#include <SFML/Graphics.hpp>
#include "object.h"


using namespace sf;
typedef enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	STOP
}m_state;
class Mob: public Object, public updatable, public drawable{
private:
	
	

	//’арактеристики скорости, здоровь€ и направлени€ движени€
	float m_speed;
	float m_health;
protected:
	m_state m_dir;
	//—прайт игрока
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	// онструктор
	Mob();
	//«десь по факту w и h задаютс€ framerect,но дл€ каноничноти € их не убрал, поэтому смотрите что в конструкторах задаЄте одинаково
	Mob(float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	Mob(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	
	//setter дл€ показателей
	void SetSprite(std::string src, sf::IntRect frameRect);
	void SetSpeed(float speed);
	void SetLife(float health);
	void SetDiraction(m_state dir);
	void SetMobParams(float  speed, float health);

	//–исование и обновление позиций игрока
	void draw(sf::RenderWindow* window);
	void update(std::vector<Object*>& solid, float elapsed_time);

	//optimize it Ќужно дл€ проверки столкновени€ моба с картой
	void CheckCollisionsWithMap(std::vector<Object*>& solid, float Dx, float Dy);
	
};