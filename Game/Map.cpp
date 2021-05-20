#include "Map.h"
#include <iostream>



Map::Map() {
	//поставить assert на ошибку загрузки
	//Загружаем дефолтную картинку в техтуру карты
	map_image.loadFromFile("images\\swamp.png");
	t_map.loadFromImage(map_image);
	s_map.setTexture(t_map);
	
	//Параметры для рисовки Tile
	Map_size = sf::Vector2f(1, 1);
	Map_position = sf::Vector2f(0, 0);
	
	
}

Map* Map::copy() {
	Map* m = new Map();
	m->SetMapLayers(layers, Map_size, Map_position);
	m->SetMapObjects(objs);
	return m;
}


void  Map::draw(RenderWindow* window) {

	for (auto l : layers) {
		sf::Sprite s;
		sf::Texture t;
		sf::Image i;
		i.loadFromFile(l.src);
		t.loadFromImage(i);
		s.setTexture(t);
		for (int i = 0; i < l.layer_size.x; i++)
		{
			for (int j = 0; j < l.layer_size.y; j++)
			{

				s.setTextureRect(l.layer_dict[l.Tile_Layer[i][j]]);
				s.setPosition(j * l.layer_size_of_texture.y, i * l.layer_size_of_texture.x);
				//по сути раскидывает квадратики, превращая в карту. 
				window->draw(s);
			}

		}
	}


}
void Map::SetMapObjects(std::vector <Object*> objects) {
	objs = objects;
}
void Map::SetMapLayers(std::vector <Layer> Layers, sf::Vector2f Map_siz, sf::Vector2f Map_pos) {
	layers = Layers;
	Map_size = Map_siz;
	Map_position = Map_pos;

}
sf::Vector2f Map::GetSize() {
	return Map_size;
}
sf::Vector2f Map::GetPos() {
	return Map_position;
}

std::vector <Object*> Map::GetObjectsByName(std::string name) {
	std::vector <Object*> vec;
	for (auto o : objs) {
		if (o->GetName() == name)
			vec.push_back(o);
	}
	return vec;
}
Object* Map::GetObjectByName(std::string name) {
	for (auto o : objs) {
		if (o->GetName() == name)
			return o;
	}
	return NULL;
}
std::vector <Object*> Map::GetObjectsByType(std::string type) {
	std::vector <Object*> vec;
	for (auto o : objs) {
		if (o->GetType() == type)
			vec.push_back(o);
	}
	return vec;
}
Object* Map::GetObjectByType(std::string type) {
	for (auto o : objs) {
		if (o->GetType() == type)
			return o;
	}
	return NULL;
}