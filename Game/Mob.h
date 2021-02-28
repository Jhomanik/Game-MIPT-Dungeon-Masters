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
	// ������� ���� � ��� ���������� ������� � ������� �� ������
	Vector2f m_position;
	Vector2f m_size;
	
	//�������� ��� ����
	Image m_image;
	Sprite m_sprite;
	Texture m_texture;

	//�������������� ��������, �������� � ����������� ��������
	float m_speed;
	float m_health;
	m_state m_dir;

public:
	//�����������
	Mob();
	//��������� ������� �� ����� 
	void Set_position(Vector2f position);

	void Set_texture(sf::String way,IntRect rect);

	Vector2f Get_coordinate();
	//������ ���������� ��������
	void move(m_state direction);
	//��������� ���� �� ����� �����������
	void update(float elapsed_time);
	//���������� ����
	void draw(RenderWindow* window);

	void interaction_with_map(Map* map);
	
};