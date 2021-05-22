#pragma once
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Menu.h"

class Mission: public drawable,public updatable
{
public:
	
	Mission(Map* map, Player* p, std::vector <Enemy*>& enemies_vec, std::vector <MeleeWeapon*>& m_weapons, MissionMenu* menu, std::string name);
	
	bool is_menu = false;
	bool is_done;
	bool show_inst = true;
	void draw(sf::RenderWindow& window);
	void update(float elapsed_time, bool& is_mission, bool& is_restart);
	void input();
	Mission* save();
	std::string GetName();
	bool GetProgress();

private:
	
	int enemy_count;
	std::string mission_name;
	std::vector <Object*> solid;
	std::vector <Enemy*> enemies;
	std::vector <MeleeWeapon*> Melee_weapons;
	std::vector <Bullet*> bullets = {};
	Map* mission_map;
	MissionMenu* mission_menu;

	
	Player* mission_player;
	
};
