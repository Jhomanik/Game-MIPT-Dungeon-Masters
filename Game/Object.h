#pragma once
#include "Basic.h"
#include <SFML/Graphics.hpp>
//Объект отвечает за физические свойства объекта и его расположение
class Object 
{
protected:
	//Имя объекта
	std::string name;
	std::string type;
	//Позиция прямоугольника - (координаты левого верхнего угла)
	sf::Vector2f position;
	
	sf::Vector2f size;
	std::string spr_source;
	sf::IntRect frame_rect;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;


public:
	Object(float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	Object(sf::Vector2f pos, sf::Vector2f size,  std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
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
	void SetSprite(std::string src, sf::IntRect frameRect);


	sf::Vector2f GetPos();
	sf::Vector2f GetSize();
	//Возвращает прямоугольник объекта
	sf::FloatRect GetRect();
	sf::Sprite GetSprite();
	std::string GetType();
	std::string GetName();


};

