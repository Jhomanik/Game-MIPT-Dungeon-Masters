#pragma once
#include "Basic.h"
#include <SFML/Graphics.hpp>
//Объект отвечает за физические свойства объекта и его расположение
class Object 
{
protected:
	//Имя объекта
	std::string name;
	//Тип - твёрдый, интерактивный и т.д
	std::string type;
	//Позиция прямоугольника - (координаты левого верхнего угла)
	sf::Vector2f position;
	//размер - ()
	sf::Vector2f size;


public:
	//3 конструктора - дефолтный, с 4 float и 2 Vector -когда пишите задание координат с векторами, обязательно добавляйте перегрузки для float и vector
	Object(float left, float top, float w, float h, std::string o_name, std::string o_type);
	Object(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type);
	Object();
	
	//setter и getter для различных полей
	void SetObject(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type);
	void SetObject(float left, float top, float w, float h, std::string o_name, std::string o_type);
	void SetPosition(sf::Vector2f pos);
	void SetSize(sf::Vector2f s);
	void SetType(std::string o_type);
	void SetName(std::string o_name);

	sf::Vector2f GetPos();
	sf::Vector2f GetSize();
	//Возвращает прямоугольник объекта
	sf::FloatRect GetRect();
	std::string GetType();
	std::string GetName();


};

