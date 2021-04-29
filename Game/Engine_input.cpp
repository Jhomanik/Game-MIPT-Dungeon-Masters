#include "Engine.h"

void Engine::input() {
    if (Keyboard::isKeyPressed(Keyboard::Space) and !isMission) {
        isMission = true;
    }
    if (Keyboard::isKeyPressed(Keyboard::Escape) and !isMission)
    {
        e_Window.close();
		
    }
    if (isMission) {
        mission->input(isMission);
    }
}