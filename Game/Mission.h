#pragma once
#include "Map.h"
#include "Player.h"
#include "Enemy.h"

class Mission: public drawable,public updatable
{
public:
	Mission();
	Mission(Map* map, Player* p, std::vector <Enemy*>& enemies_vec, std::vector <MeleeWeapon*>& m_weapons);
	

	void draw(sf::RenderWindow& window);
	void update(float elapsed_time);
	void input(bool & isMission);

private:
	

	std::vector <Object*> solid;
	std::vector <Enemy*> enemies;
	std::vector <MeleeWeapon*> Melee_weapons;
	Map* mission_map;

	
	Player* mission_player;
	
};
