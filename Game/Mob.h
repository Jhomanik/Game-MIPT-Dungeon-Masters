#pragma once
#include <SFML/Graphics.hpp>
#include "Basic.h"
#include "Map.h"

using namespace sf;
typedef enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	STOP
}m_state;
class Mob:public updatable, public drawable{
private:
	// Позиция моба и его физические размеры в расчете от центра
	Vector2f m_position;
	Vector2f m_size;
	
	//Картинка для моба
	Image m_image;
	Sprite m_sprite;
	Texture m_texture;

	//Характеристики скорости, здоровья и наспраления движения
	float m_speed;
	float m_health;
	m_state m_dir;

public:
	//Конструктор
	Mob();
	//Назначить позицию по карте 
	void Set_position(Vector2f position);

	void Set_texture(sf::String way,IntRect rect);

	Vector2f Get_coordinate();
	//Задать напрвления движения
	void move(m_state direction);
	//Подвинуть моба по новым координатам
	void update(float elapsed_time);
	//Отрисовать моба
	void draw(RenderWindow* window);

	void interaction_with_map(Map* map);
	
};