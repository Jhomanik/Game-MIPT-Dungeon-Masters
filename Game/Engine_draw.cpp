#include "Engine.h"
void Engine::draw() {
    //������� ����


    
    if (is_mission)
    {
        mission->draw(e_Window);
    }
    else
    {
        e_Window.clear(sf::Color(0, 0, 100, 0));
        main_menu->draw(e_Window);
        e_Window.display();
    }
}