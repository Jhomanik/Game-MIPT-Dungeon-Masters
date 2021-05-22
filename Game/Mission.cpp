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
	std::vector <Bullet*> new_bullets;
	for (auto b : bullets) {
		new_bullets.push_back(b->copy());
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
			MeleeWeapon* w = e->GetMW()->copy();
			e->SetMeleeWeapon(w);

			weapons.push_back(w);

		}
		
	}
	return new Mission(map, p, ens, weapons, menu, mission_name);
}
std::string Mission::GetName() {
	return mission_name;
}
void Mission::draw(sf::RenderWindow& window) {

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
		for (auto b : bullets) {
			b->draw(&window);
		}
		mission_player->draw(&window);
		//����� ��� ������
		Font font;//����� 
		font.loadFromFile("fonts\\CyrilicOld.ttf");//�������� ������ ������ ���� ������

		Text task("", font, 80);
		task.setFillColor(sf::Color::Red);
		task.setStyle(sf::Text::Bold);
		if (mission_player->GetIsLife())
		{
			if (!is_done) {

				task.setString("Enemies left :" + std::to_string(enemy_count));

			}
			else {
				task.setString("Completed\n");
			}
			task.setPosition(VideoMode::getDesktopMode().width - task.getGlobalBounds().width - 50, VideoMode::getDesktopMode().height - task.getGlobalBounds().height - 50);

		}
		else {
			
			task.setString("YOU ARE DEAD");
			task.setScale(2, 2);
			task.setPosition(VideoMode::getDesktopMode().width - task.getGlobalBounds().width*1.3, VideoMode::getDesktopMode().height/2 - task.getLocalBounds().height*2);

		}

		window.draw(task);

		//���������� ��� �������
		
		Text inst("", font, 45);
		inst.setFillColor(sf::Color::Black);
		sf::Texture list_texture;
		list_texture.loadFromFile("images\\list.png");
		sf::Sprite list_sprite;
		list_sprite.setTexture(list_texture);
	
		inst.setStyle(sf::Text::Bold);
		inst.setScale(0.8, 1.2);
		std::string s;
		float delta;
		if (show_inst)
		{
			s = "\t  Hide";
			delta = 320;
		}
		else{
			s = "\t  Show";
			delta = 60;
		}
		list_sprite.setPosition(0, VideoMode::getDesktopMode().height - 75 -delta);
		inst.setString(s + "- I \n Move - W,A,S,D\n Pick up - F \n Attack - G ,LMB \n Swap weapon - E \n Drop - Q");
		inst.setPosition(90, VideoMode::getDesktopMode().height - delta);
		window.draw(list_sprite);
		window.draw(inst);
	}
	else
	{
		mission_menu->draw(window);
	}


	// ���������� ���, ��� ����������
	
}

void Mission::update(float  elapsed_time, bool& is_mission, bool& is_restart) {
	if (is_mission)
	{
		if (!is_menu)
		{
			if (mission_player->GetIsLife()) {

				enemy_count = enemies.size();
				if (enemy_count != 0)
					is_done = false;
				else {
					is_done = true;
				}

				mission_player->update(solid, enemies, Melee_weapons, elapsed_time);
				for (int i = 0; i < bullets.size(); i++) {
					if (bullets[i]->GetState()) {
						bullets.erase(bullets.begin() + i);
					}
					else {
						bullets[i]->update(solid, mission_player, elapsed_time);
					}
				}


				for (int i = 0; i < enemies.size(); i++) {
					if (enemies[i]->GetIsLife())
						enemies[i]->update(solid, mission_player, bullets, elapsed_time);
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
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
				show_inst = (show_inst) ? false : true;
			mission_player->input();
		}
		else
			is_menu = true;
	}
	
}
bool Mission::GetProgress() {
	return is_done;
}