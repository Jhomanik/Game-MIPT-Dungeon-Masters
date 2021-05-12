#include "Engine.h"
void Engine::update(float elapsed_time) {
	input_timer = std::max(input_timer - elapsed_time, float(0));
	if (!is_over)
	{
		if (is_mission)
		{
			mission->update(elapsed_time,is_mission);
		}
		else {
			main_menu->update(is_mission, is_over);
		}
	}
	else {
		e_Window.close();
	}
}