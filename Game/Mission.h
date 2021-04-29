#pragma once
#include "Map.h"
#include "Player.h"
class Mission: public drawable,public updatable
{
public:
	Mission();
	Mission(Map* map, Player* p);
	

	void draw(sf::RenderWindow& window);
	void update(float time_mcs);
	void input(bool & isMission);

private:
	Map* mission_map;
	std::vector <Object*> solid;
	Player* mission_player;
};
