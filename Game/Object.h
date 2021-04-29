#pragma once
#include "Basic.h"
#include <SFML/Graphics.hpp>
//������ �������� �� ���������� �������� ������� � ��� ������������
class Object 
{
protected:
	//��� �������
	std::string name;
	//��� - ������, ������������� � �.�
	std::string type;
	//������� �������������� - (���������� ������ �������� ����)
	sf::Vector2f position;
	//������ - ()
	sf::Vector2f size;


public:
	//3 ������������ - ���������, � 4 float � 2 Vector -����� ������ ������� ��������� � ���������, ����������� ���������� ���������� ��� float � vector
	Object(float left, float top, float w, float h, std::string o_name, std::string o_type);
	Object(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type);
	Object();
	
	//setter � getter ��� ��������� �����
	void SetObject(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type);
	void SetObject(float left, float top, float w, float h, std::string o_name, std::string o_type);
	void SetPosition(sf::Vector2f pos);
	void SetSize(sf::Vector2f s);
	void SetType(std::string o_type);
	void SetName(std::string o_name);

	sf::Vector2f GetPos();
	sf::Vector2f GetSize();
	//���������� ������������� �������
	sf::FloatRect GetRect();
	std::string GetType();
	std::string GetName();


};

