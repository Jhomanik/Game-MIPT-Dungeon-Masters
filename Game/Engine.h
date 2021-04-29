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

    //���������� � ������ �� ����������
    bool isMission;

    // �������� ������
   
    Mission* mission;

    //�����, ������������ ���� � �������������� �� ����� ��������� ���������� ����
    void input();
    //�����, ����������� ���������� ���� ����������� �������� ��������� ���� 
    void update(float time_mcs);
    //�����, �������� ��� ��������
    void draw();

public:
    // ����������� ������
    Engine();
    // ������� ����� ������� ��� ��������� ������� � ������ ������ ������(�� ��� ����)
    void start();
    
};
