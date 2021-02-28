#include "Engine.h"

void Engine::input() {
	bool is_pressed = 0;
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        e_Window.close();
		is_pressed = 1;
    }
	
	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) {
		e_active->move(LEFT);
		is_pressed = 1;

	}
	
	if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
		e_active->move(RIGHT);
		is_pressed = 1;
	}

	if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)) {
		e_active->move(UP);
		is_pressed = 1;
	}

	if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)) {
		e_active->move(DOWN);
		is_pressed = 1;
	}
	if(!is_pressed){
		e_active->move(STOP);
	}



}