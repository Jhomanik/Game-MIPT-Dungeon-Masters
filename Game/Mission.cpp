#include"Mission.h"

Mission::Mission() {
	mission_map = NULL;
	solid = {};
	mission_player = NULL;
}
Mission::Mission(Map* map, Player* p, std::vector <Enemy*>& enemies_vec, std::vector <MeleeWeapon*>& m_weapons) {
	mission_map = map;
	
	mission_player = p;
	solid = mission_map->GetObjectsByType("solid");
	enemies = enemies_vec;
	
	Melee_weapons = m_weapons;
}
 
void Mission::draw(sf::RenderWindow& window) {
	window.clear(sf::Color(0,0,0,255));
	mission_map->draw(&window);
	window.draw(mission_player->GetAttackShape());
	for (auto enemy : enemies) {
		
		enemy->draw(&window);
	}
	for (auto w : Melee_weapons) {
		if(!w->GetWithMob())
			w->draw(&window);
	}
	mission_player->draw(&window);
	//Тескт для выхода
	Font font;//шрифт 
	font.loadFromFile("fonts\\CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
	Text text("", font, 45);
	text.setFillColor(sf::Color::Yellow);
	text.setString("Press BackSpace to exit");
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(VideoMode::getDesktopMode().width / 2 - 200, VideoMode::getDesktopMode().height / 2 - 100);
	window.draw(text);

	//Инструкция для ламеров
	
	Text inst("", font, 45);
	inst.setFillColor(sf::Color::Yellow);
	inst.setString("Move - W,A,S,D\n Pick up - F \n Attack - G ,LMB \n Swap weapon - E \n Drop - Q");
	inst.setStyle(sf::Text::Bold );
	inst.setPosition(VideoMode::getDesktopMode().width / 2 , 100);
	window.draw(inst);

	window.display();

	// Отображаем все, что нарисовали
	
}

void Mission::update(float  elapsed_time) {
	mission_player->update(solid, enemies,Melee_weapons, elapsed_time);
	std::vector <Player*> players = { mission_player };
	for (int i = 0; i < enemies.size();i++) {
		if(enemies[i]->GetIsLife())
			enemies[i]->update(solid, players, elapsed_time);
		else {
			enemies[i]->Kill();
			enemies.erase(enemies.begin()+i);
		}
	}
	for (auto mw : Melee_weapons) {
		if (!mw->GetWithMob())
			mw->update(elapsed_time, mission_player);
	}
}

void Mission::input(bool & isMission) {
	if (Keyboard::isKeyPressed(Keyboard::BackSpace))
	{
		isMission = false;
	}
	else
		mission_player->input();
	
}