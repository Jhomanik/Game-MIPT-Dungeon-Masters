#pragma once
#include <SFML/Graphics.hpp>
#include "Mob.h";
#include "Map.h"

using namespace sf;

class Engine
{
private:

    //���� ��� ����������� ����
    RenderWindow e_Window;

    // ��������� ������ � �������� ��� ����
    Image background_image;
    Sprite background_sprite;
    Texture background_texture;

    // Active player
   
    Mob* e_active;
    Map* e_map;

    //�����, ������������ ���� � �������������� �� ����� ��������� ���������� ����
    void input();
    //�����, ����������� ���������� ���� ����������� �������� ��������� ���� 
    void update(float time_mcs);
    //�����, �������� ��� ��������
    void draw();

public:
    // ����������� ������
    Engine();
    // ������� ����� ������� ��� ��������� �������
    void start();
};
