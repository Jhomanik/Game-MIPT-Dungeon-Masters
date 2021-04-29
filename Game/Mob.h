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
	
	

	//�������������� ��������, �������� � ����������� ��������
	float m_speed;
	float m_health;
protected:
	m_state m_dir;
	//������ ������
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	//�����������
	Mob();
	//����� �� ����� w � h �������� framerect,�� ��� ����������� � �� �� �����, ������� �������� ��� � ������������� ������ ���������
	Mob(float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	Mob(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	
	//setter ��� �����������
	void SetSprite(std::string src, sf::IntRect frameRect);
	void SetSpeed(float speed);
	void SetLife(float health);
	void SetDiraction(m_state dir);
	void SetMobParams(float  speed, float health);

	//��������� � ���������� ������� ������
	void draw(sf::RenderWindow* window);
	void update(std::vector<Object*>& solid, float elapsed_time);

	//optimize it ����� ��� �������� ������������ ���� � ������
	void CheckCollisionsWithMap(std::vector<Object*>& solid, float Dx, float Dy);
	
};