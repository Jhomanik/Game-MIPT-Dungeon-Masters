#include "Engine.h"
void Engine::draw() {
    //очищаем окно


    
    if (isMission)
    {
        mission->draw(e_Window);
    }
    else
    {
        e_Window.clear(sf::Color(0, 0, 100, 0));
        Font font;//шрифт 
        font.loadFromFile("fonts\\CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
        Text text("", font, 45);
        text.setFillColor(sf::Color::Yellow);
        text.setString("Press Space to play \n Press Esc to exit");
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        text.setPosition(VideoMode::getDesktopMode().width/2 - 200, VideoMode::getDesktopMode().height/2 - 100);
        e_Window.draw(text);


        

        e_Window.display();
    }
}