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
    int curr_mission_num = 0;
    bool is_mission;
    int total_progress = 0;
    bool is_over = false;
    bool is_restart_curr_mission = false;
    bool is_choice_menu = false;
    MainMenu* main_menu;
    ChoiceMenu* choice_menu;

    // �������� ������
    std::vector <std::pair<Mission*, Mission*>> Saves;
    Mission* mission;
    Mission* r_mission;
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
