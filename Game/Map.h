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
	//��������� ��������� �������� � ������� �����
	Image map_image;
	Texture t_map;
	Sprite s_map;

	std::vector <Layer> layers;

	//��� ��������� ������� ��� ��������� 
	std::vector <Object*> objs;

	//��������� ��� ������� Tile
	sf::Vector2f Map_size;
	sf::Vector2f Map_position;
	
public:
	//�����������
	Map(); 

	void SetMapLayers(std::vector <Layer> layers, sf::Vector2f Map_siz, sf::Vector2f Map_pos );
	void SetMapObjects(std::vector <Object*> objects);
	//����� ������� �����
	Vector2f GetSize();
	//����� ���������� ������ �������� ����
	Vector2f GetPos();
	//�������������� �����, �������� �����
	void draw(RenderWindow* window);
	std::vector <Object*> GetObjectsByName(std::string name);
	Object* GetObjectByName(std::string name);
	std::vector <Object*> GetObjectsByType(std::string type);
	Object* GetObjectByType(std::string type);
};