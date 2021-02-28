#include "Engine.h"
void Engine::draw() {
    //очищаем окно
    e_Window.clear(Color::White);

   

    e_map->draw(&e_Window);
    e_active->draw(&e_Window);


    // Отображаем все, что нарисовали
    e_Window.display();
}