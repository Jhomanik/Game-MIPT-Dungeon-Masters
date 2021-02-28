#pragma once
#include <SFML/Graphics.hpp>
#include "Basic.h"
#include <map>
#include <Vector>

using namespace sf;


class Map: public drawable {
private:
	//��������� ��������� �������� � ������� �����
	Image map_image;
	Texture t_map;
	Sprite s_map;

	//Map ��� ������������� ��������� Tile � �� �������� 
	std::map <char, IntRect> map_dict;
	int size_of_texture;

	//��������� ��� ������� Tile
	int Map_height;
	int Map_width;
	Vector2f Map_position;
	std::vector<String> Tile_Map;
public:
	//�����������
	Map(); 
	//����� ������� �����
	Vector2f get_size();
	//����� ���������� ������ �������� ����
	Vector2f get_coor();
	//����� ��������� Tile
	void Set_tile(std::vector<String>& tile, int height, int width); 
	//����� ������ ��� ��������� Tile
	void Set_sprite(String way, std::map <char, IntRect>& dict, int size);
	//�������������� �����, �������� �����
	void draw(RenderWindow* window);
};