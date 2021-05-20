#include "Engine.h"
void Engine::update(float elapsed_time) {
	input_timer = std::max(input_timer - elapsed_time, float(0));
	if (!is_over)
	{
		Saves[curr_mission_num].first = mission;
		total_progress = 0;
		for (int i = 0; i < Saves.size(); i++) {
			if (Saves[i].first->GetProgress()) {
				choice_menu->MarkButton(i,true);
				total_progress += 1;
			}
			else {
				choice_menu->MarkButton(i,false);
			}
		}

		if (is_restart_curr_mission) {

			delete mission;
			Font font;//רנטפע 
			font.loadFromFile("fonts\\CyrilicOld.ttf");//ןונוהאול םארולף רנטפעף פאיכ רנטפעא



			e_Window.clear(sf::Color(0, 0, 0, 0));
			Text load("", font, 120);
			load.setFillColor(sf::Color::White);
			load.setString("Loading...");
			load.setStyle(sf::Text::Bold);
			load.setPosition(VideoMode::getDesktopMode().width / 2 - load.getLocalBounds().width / 2, VideoMode::getDesktopMode().height / 2 - load.getLocalBounds().height);
			e_Window.draw(load);
			e_Window.display();

			mission = r_mission->save();
			is_restart_curr_mission = false;
		}
		else {
			if (is_mission)
			{
				mission->update(elapsed_time, is_mission, is_restart_curr_mission);
			}
			else
			{
				if (is_choice_menu) {
					choice_menu->update(is_choice_menu, curr_mission_num);
					mission = Saves[curr_mission_num].first;
					r_mission = Saves[curr_mission_num].second;
				}
				else
				{
					main_menu->update(is_mission, is_choice_menu, is_over);
				}
			}
		}
	}
	else {
		e_Window.close();
	}
}