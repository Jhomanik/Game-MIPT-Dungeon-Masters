#include "Map.h"
#include <iostream>

using namespace sf;

Map::Map() {
	//поставить assert на ошибку загрузки
	//Загружаем дефолтную картинку в техтуру карты
	map_image.loadFromFile("images\\swamp.png");
	t_map.loadFromImage(map_image);
	s_map.setTexture(t_map);
	
	
	map_dict = {};
	
	
	//Параметры для рисовки Tile
	Map_height = 0;
	Map_width = 0;
	Map_position = Vector2f(0, 0);
	size_of_texture = 0;
	Tile_Map = {};
	
}
void Map::Set_sprite (String way, std::map<char,IntRect>& dict,int size) {
	

	//поставить assert на ошибку загрузки
	map_image.loadFromFile(way);//загружаем файл для карты
	t_map.loadFromImage(map_image);//заряжаем текстуру картинкой
	s_map.setTexture(t_map);//заливаем текстуру спрайтом

	
	map_dict.insert(dict.begin(), dict.end());
	size_of_texture = size;

}

void Map::Set_tile(std::vector <String>& tile, int height, int width) {

	Tile_Map = tile;
	Map_height = height;
	Map_width = width;

}

void  Map::draw(RenderWindow* window) {
	

	for (int i = 0; i < Map_height; i++)
	{
		for (int j = 0; j < Map_width; j++)
		{
		
			s_map.setTextureRect(map_dict[Tile_Map[i][j]]); 
			s_map.setPosition(j * size_of_texture, i * size_of_texture);
			//по сути раскидывает квадратики, превращая в карту. 
			window->draw(s_map);
		}

	}
	

}

Vector2f Map::get_size() {
	return Vector2f(Map_height, Map_width);
}
Vector2f Map::get_coor() {
	return Map_position;
}