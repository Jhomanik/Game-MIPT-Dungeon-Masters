#include "Engine.h"
void Engine::draw() {
    //очищаем окно
    e_Window.clear(sf::Color(0, 0, 0));


    
    if (is_mission)
    {
        mission->draw(e_Window);
    }
    else
    {
        
        if (is_choice_menu) {
            choice_menu->draw(e_Window);
        }
        else
        {
            sf::Font font;
            font.loadFromFile("Fonts\\CyrilicOld.TTF");
            main_menu->draw(e_Window);
            Text progress("", font, 60);
            progress.setFillColor(sf::Color::White);
            progress.setStyle(sf::Text::Bold);
            
            
            if (total_progress != Saves.size()) {
                progress.setString(std::to_string(Saves.size() - total_progress) + " left to go");
                progress.setPosition(VideoMode::getDesktopMode().width / 2 - progress.getGlobalBounds().width / 2 , 150);
            }
            else {

                
                progress.setString("Completed! You are Dungeon Master!!! ");
                progress.setPosition(VideoMode::getDesktopMode().width / 2 - progress.getGlobalBounds().width / 2 , 150);
            }

            e_Window.draw(progress);
        }
    }
    e_Window.display();
}