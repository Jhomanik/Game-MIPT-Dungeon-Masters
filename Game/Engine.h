#pragma once

#include "Mission.h"


using namespace sf;

class Engine
{
private:

    //Окно для отобрадения игры
    RenderWindow e_Window;

    // Объявляем спрайт и текстуру для фона
    Image background_image;
    Sprite background_sprite;
    Texture background_texture;
    float input_timer = 0;
    float input_time = 110;
    //Показатель в миссии ли управление
    int curr_mission_num = 0;
    bool is_mission;
    int total_progress = 0;
    bool is_over = false;
    bool is_restart_curr_mission = false;
    bool is_choice_menu = false;
    MainMenu* main_menu;
    ChoiceMenu* choice_menu;

    // Активная миссия
    std::vector <std::pair<Mission*, Mission*>> Saves;
    Mission* mission;
    Mission* r_mission;
    //Метод, регулирующий ввод и распределяющий их между активными элементами игры
    void input();
    //Метод, запускающий обновление всех обновляемых активных элементов игры 
    void update(float elapsed_time);
    //Метод, рисующий все элементы
    void draw();

public:
    // Конструктор движка
    Engine();
    // Функция старт вызовет все приватные функции и задают первую миссию(но это пока)
    void start();
    
};
