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

    //Показатель в миссии ли управление
    bool isMission;

    // Активная миссия
   
    Mission* mission;

    //Метод, регулирующий ввод и распределяющий их между активными элементами игры
    void input();
    //Метод, запускающий обновление всех обновляемых активных элементов игры 
    void update(float time_mcs);
    //Метод, рисующий все элементы
    void draw();

public:
    // Конструктор движка
    Engine();
    // Функция старт вызовет все приватные функции и задают первую миссию(но это пока)
    void start();
    
};
