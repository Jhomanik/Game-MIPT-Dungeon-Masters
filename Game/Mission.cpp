#include"Mission.h"


Mission::Mission(Map* map, Player* p, std::vector <Enemy*>& enemies_vec, std::vector <MeleeWeapon*>& m_weapons,MissionMenu* menu, std::string name) {
	mission_map = map;
	mission_player = p;
	solid = mission_map->GetObjectsByType("solid");
	enemies = enemies_vec;
	mission_menu = menu;
	Melee_weapons = m_weapons;
	enemy_count = enemies.size();
	mission_name = name;
}
Mission* Mission::save() {
	Map* map = mission_map->copy();
	MissionMenu* menu = mission_menu->copy();
	Player* p = mission_player->copy();
	std::vector <Enemy*> ens;
	for (auto e : enemies) {
		ens.push_back(e->copy());
	}
	std::vector <MeleeWeapon*> weapons;
	for (auto w : Melee_weapons) {
		if (!w->GetWithMob())
		{
			weapons.push_back(w->copy());
		}
	}
	for (auto e : ens) {
		if (e->GetMW() != nullptr) {
			weapons.push_back((e->GetMW())->copy());
		}
	}
	return new Mission(map, p, ens, weapons, menu, mission_name);
}
std::string Mission::GetName() {
	return mission_name;
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

		Text task("", font, 80);
		task.setFillColor(sf::Color::Red);
		task.setStyle(sf::Text::Bold);
		task.setPosition(VideoMode::getDesktopMode().width / 2 - task.getGlobalBounds().width/2, VideoMode::getDesktopMode().height / 2);

		if (!is_done) {
			
			task.setString("Enemies left :" + std::to_string(enemy_count));

		}
		else {
			task.setString("Completed\n");
		}
		window.draw(task);

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

void Mission::update(float  elapsed_time, bool& is_mission, bool& is_restart) {
	if (is_mission)
	{
		if (!is_menu)
		{
			enemy_count = enemies.size();
			if (enemy_count != 0)
				is_done = false;
			else{
				is_done = true;
			}
		
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
			mission_menu->update(is_menu, is_restart, is_mission);
			if (!is_mission || is_restart) {
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
bool Mission::GetProgress() {
	return is_done;
}