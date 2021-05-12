#include "Engine.h"

void Engine::input() {
    sf::Event event;
    e_Window.pollEvent(event);
    
        if ( input_timer == 0. || !event.type == sf::Event::KeyPressed)
        {
            if (!is_over) {
                if (is_mission) {
                    mission->input();
                }
                else {
                    main_menu->input();
                }
            }
            if(input_timer == 0.)
                input_timer = input_time;
        }

    
}