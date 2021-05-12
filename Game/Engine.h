#pragma once

#include "Mission.h"


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
    float input_timer = 0;
    float input_time = 110;
    //���������� � ������ �� ����������
    bool is_mission;
    bool is_over = false;

    MainMenu* main_menu;

    // �������� ������
   
    Mission* mission;

    //�����, ������������ ���� � �������������� �� ����� ��������� ���������� ����
    void input();
    //�����, ����������� ���������� ���� ����������� �������� ��������� ���� 
    void update(float elapsed_time);
    //�����, �������� ��� ��������
    void draw();

public:
    // ����������� ������
    Engine();
    // ������� ����� ������� ��� ��������� ������� � ������ ������ ������(�� ��� ����)
    void start();
    
};
