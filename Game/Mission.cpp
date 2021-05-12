#include"Mission.h"

Mission::Mission() {
	mission_map = NULL;
	mission_menu = NULL;
	solid = {};
	mission_player = NULL;
}
Mission::Mission(Map* map, Player* p, std::vector <Enemy*>& enemies_vec, std::vector <MeleeWeapon*>& m_weapons,MissionMenu* menu) {
	mission_map = map;
	
	mission_player = p;
	solid = mission_map->GetObjectsByType("solid");
	enemies = enemies_vec;
	mission_menu = menu;
	Melee_weapons = m_weapons;
}
 
void Mission::draw(sf::RenderWindow& window) {
	window.clear(sf::Color(0,0,0,255));
	if (!is_menu)
	{
		mission_map->draw(&window);
		window.draw(mission_player->GetAttackShape());
		for (auto enemy : enemies) {

			enemy->draw(&window);
		}
		for (auto w : Melee_weapons) {
			if (!w->GetWithMob())
				w->draw(&window);
		}
		mission_player->draw(&window);
		//Тескт для выхода
		Font font;//шрифт 
		font.loadFromFile("fonts\\CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
		

		//Инструкция для ламеров

		Text inst("", font, 45);
		inst.setFillColor(sf::Color::Yellow);
		inst.setString("Move - W,A,S,D\n Pick up - F \n Attack - G ,LMB \n Swap weapon - E \n Drop - Q");
		inst.setStyle(sf::Text::Bold);
		inst.setPosition(VideoMode::getDesktopMode().width / 2, 100);
		window.draw(inst);
	}
	else
	{
		mission_menu->draw(window);
	}

	window.display();

	// Отображаем все, что нарисовали
	
}

void Mission::update(float  elapsed_time, bool& is_mission) {
	if (is_mission)
	{
		if (!is_menu)
		{
			mission_player->update(solid, enemies, Melee_weapons, elapsed_time);
			std::vector <Player*> players = { mission_player };
			for (int i = 0; i < enemies.size(); i++) {
				if (enemies[i]->GetIsLife())
					enemies[i]->update(solid, players, elapsed_time);
				else {
					enemies[i]->Kill();
					enemies.erase(enemies.begin() + i);
				}
			}
			for (auto mw : Melee_weapons) {
				if (!mw->GetWithMob())
					mw->update(elapsed_time, mission_player);
			}
		}
		else
		{
			mission_menu->update(is_menu, is_mission);
			if (!is_mission) {
				is_menu = false;
			}

		}
		
	}
}

void Mission::input() {
	if (is_menu) {
		mission_menu->input();
		
	}
	else {
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			mission_player->input();
		else
			is_menu = true;
	}
	
}