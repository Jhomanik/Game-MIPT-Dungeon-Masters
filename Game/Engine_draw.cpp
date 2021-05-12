#include "Engine.h"
void Engine::draw() {
    //очищаем окно


    
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