#include "Engine.h"

Engine::Engine() {
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	e_Window.create(VideoMode(resolution.x,resolution.y), "Game",Style::Fullscreen);
	background_image.loadFromFile("images\\swamp.png");
	background_texture.loadFromImage(background_image);
	background_sprite.setTexture(background_texture);
	mission = NULL;
	isMission = false;
}



void Engine::start() {
	Clock clock;


	//Задание миссии
	Player* e_active = new Player(sf::Vector2f(100, 100),sf::Vector2f(32+12,32), "Player", "Mob", "images\\roguelikeitems.png", IntRect(0, 32 * 14 - 10, 32 + 12, 32));
	
	Map* e_map = new Map();
	std::vector <String> Tile = {"sssssssssssssss",
								 "sttttttttttttts",
								 "sttttttttttttts",
								 "sttttttttttttts",
								"sttttttttttttts",
								"sttttttssstttts",
								"sttttttttttttts",
								"sttttttttttttts",
								"sttttttttttttts",
								 "sssssssssssssss" };
	std::map <char, IntRect> dict = { {'t',IntRect(0,0,32,32)},{'s',IntRect(32,0,32,32)} };
	e_map->SetMapLayers({ {"images\\default.png", dict , sf::Vector2f(32,32), Tile,sf::Vector2f(10,15) } }, sf::Vector2f(1000,1000), sf::Vector2f(0,0) );
	e_map->SetMapObjects({  new Object(0,0,32,32*10, "wal","solid"),
							 new Object(0,32*9,32 * 15,32, "wal","solid"),
							 new Object(0,0,32*15,32,"wal","solid"),
							 new Object(32*14,0,32,32*10,"wal","solid"),
								new Object(7*32, 5*32, 3*32,32, "wal","solid")});
	mission = new Mission(e_map, e_active);
	

	//Главный цикл движка
	while (e_Window.isOpen()) {

		float time_mcsec = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time_mcsec = time_mcsec / 1000;
		input();
		update(time_mcsec);
		draw();
	}
	
}