#include "Engine.h"
void Engine::draw() {
    //������� ����
    e_Window.clear(Color::White);

   

    e_map->draw(&e_Window);
    e_active->draw(&e_Window);


    // ���������� ���, ��� ����������
    e_Window.display();
}