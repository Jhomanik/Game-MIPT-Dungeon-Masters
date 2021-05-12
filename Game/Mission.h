#pragma once
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Menu.h"

class Mission: public drawable,public updatable
{
public:
	Mission();
	Mission(Map* map, Player* p, std::vector <Enemy*>& enemies_vec, std::vector <MeleeWeapon*>& m_weapons, MissionMenu* menu);
	
	bool is_menu = false;
	void draw(sf::RenderWindow& window);
	void update(float elapsed_time, bool& is_mission);
	void input();

private:
	

	std::vector <Object*> solid;
	std::vector <Enemy*> enemies;
	std::vector <MeleeWeapon*> Melee_weapons;
	Map* mission_map;
	MissionMenu* mission_menu;

	
	Player* mission_player;
	
};
