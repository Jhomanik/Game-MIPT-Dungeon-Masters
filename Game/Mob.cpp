#include <SFML/Graphics.hpp>
#include "Mob.h"

Mob::Mob(){
	m_position = Vector2f(0,0);
	m_size.x = 1;
	m_size.y = 1;

	m_health = 100.;
	m_speed = 0.5;
	m_dir = STOP;

	//поставить assert на ошибку загрузки
	m_image.loadFromFile("images\\shrek-pixel.png");
	m_texture.loadFromImage(m_image);
	m_sprite.setTexture(m_texture);
}
Vector2f Mob::Get_coordinate() {
	return m_position;
}

void Mob::Set_texture(String way,IntRect rect) {
	
	//поставить assert на ошибку загрузки	
	m_image.loadFromFile(way);
	m_texture.loadFromImage(m_image);
	m_sprite.setTextureRect(rect);
}
void Mob::Set_position(Vector2f position) {
	m_position = position;
}

void Mob::move(m_state direction) {
	m_dir = direction;
}
void Mob::update(float elapsed_time) {
	//Изменение направления в зависимости от движения 
	switch (m_dir)
	{
	case UP:
		m_position += Vector2f(0, -elapsed_time * m_speed);
		break;
	case DOWN:
		m_position += Vector2f(0, elapsed_time * m_speed);
		break;
	case LEFT:
		m_position += Vector2f(-elapsed_time * m_speed,0);
		break;
	case RIGHT:
		m_position += Vector2f(elapsed_time * m_speed,0);
		break;
	default:

		break;
	}
	m_sprite.setPosition(m_position);
}
void Mob::draw(RenderWindow* window) {
	window->draw(m_sprite);
}

/*void Mob::interaction_with_map(Map* map) {
	int height = map->get_size().x;
	int weight = map->get_size().y;
	float x0 = map->get_coor().x;
	float y0 = map->get_coor().y;
	for(int i Map.)

}*/
