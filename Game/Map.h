#pragma once
#include <SFML/Graphics.hpp>
#include "Basic.h"
#include"object.h"
#include <map>
#include <Vector>

using namespace sf;

struct Layer {
	std::string src;
	std::map <char, IntRect> layer_dict;
	sf::Vector2f layer_size_of_texture;
	std::vector<String> Tile_Layer;
	sf::Vector2f layer_size;
};
class Map: public drawable {
private:
	//Загружаем дефолтную картинку в техтуру карты
	Image map_image;
	Texture t_map;
	Sprite s_map;

	std::vector <Layer> layers;

	//Все статичные объекты для отрисовки 
	std::vector <Object*> objs;

	//Параметры для рисовки Tile
	sf::Vector2f Map_size;
	sf::Vector2f Map_position;
	
public:
	//Конструктор
	Map(); 

	void SetMapLayers(std::vector <Layer> layers, sf::Vector2f Map_siz, sf::Vector2f Map_pos );
	void SetMapObjects(std::vector <Object*> objects);
	//Выдаёт размеры карты
	Vector2f GetSize();
	//Выдаёт координаты левого верхнего угла
	Vector2f GetPos();
	//Унаследованный метод, рисующий карту
	void draw(RenderWindow* window);
	std::vector <Object*> GetObjectsByName(std::string name);
	Object* GetObjectByName(std::string name);
	std::vector <Object*> GetObjectsByType(std::string type);
	Object* GetObjectByType(std::string type);
};