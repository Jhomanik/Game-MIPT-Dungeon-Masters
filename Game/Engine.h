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
    bool is_mission;
    bool is_over = false;

    MainMenu* main_menu;

    // Активная миссия
   
    Mission* mission;

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
