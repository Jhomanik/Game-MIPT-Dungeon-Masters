#include"Mission.h"

Mission::Mission() {
	mission_map = NULL;
	solid = {};
	mission_player = NULL;
}
Mission::Mission(Map* map, Player* p) {
	mission_map = map;
	mission_player = p;
	solid = mission_map->GetObjectsByType("solid");
	
}
 
void Mission::draw(sf::RenderWindow& window) {
	window.clear(sf::Color(0,0,0,255));
	mission_map->draw(&window);
	mission_player->draw(&window);

	Font font;//øğèôò 
	font.loadFromFile("fonts\\CyrilicOld.ttf");//ïåğåäàåì íàøåìó øğèôòó ôàéë øğèôòà
	Text text("", font, 45);
	text.setFillColor(sf::Color::Yellow);
	text.setString("Press BackSpace to exit");
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(VideoMode::getDesktopMode().width / 2 - 200, VideoMode::getDesktopMode().height / 2 - 100);
	window.draw(text);

	window.display();

	// Îòîáğàæàåì âñå, ÷òî íàğèñîâàëè
	
}

void Mission::update(float  time_mcs) {
	mission_player->update(solid ,time_mcs);
}

void Mission::input(bool & isMission) {
	if (Keyboard::isKeyPressed(Keyboard::BackSpace))
	{
		isMission = false;
	}
	else
		mission_player->input();
	
}