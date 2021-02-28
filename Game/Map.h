#pragma once
#include <SFML/Graphics.hpp>
#include "Basic.h"
#include <map>
#include <Vector>

using namespace sf;


class Map: public drawable {
private:
	//Загружаем дефолтную картинку в техтуру карты
	Image map_image;
	Texture t_map;
	Sprite s_map;

	//Map для сопоставления элементов Tile и их спрайтов 
	std::map <char, IntRect> map_dict;
	int size_of_texture;

	//Параметры для рисовки Tile
	int Map_height;
	int Map_width;
	Vector2f Map_position;
	std::vector<String> Tile_Map;
public:
	//Конструктор
	Map(); 
	//Выдаёт размеры карты
	Vector2f get_size();
	//Выдаёт координаты левого верхнего угла
	Vector2f get_coor();
	//Задаёт структуру Tile
	void Set_tile(std::vector<String>& tile, int height, int width); 
	//Задаёт данные для отрисовки Tile
	void Set_sprite(String way, std::map <char, IntRect>& dict, int size);
	//Унаследованный метод, рисующий карту
	void draw(RenderWindow* window);
};