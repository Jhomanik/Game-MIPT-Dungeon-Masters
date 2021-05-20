#include "Engine.h"
#include <fstream>
Engine::Engine() {
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	e_Window.create(VideoMode(resolution.x,resolution.y), "Game",Style::Fullscreen);
	background_image.loadFromFile("images\\swamp.png");
	background_texture.loadFromImage(background_image);
	background_sprite.setTexture(background_texture);
	mission = NULL;
	r_mission = NULL;
	is_mission = false;
	main_menu = NULL;
}



void Engine::start() {
	Clock clock;

	//Меню 
	std::vector <Button*> main_menu_buttons = { new Button ("Fonts\\CyrilicOld.TTF", "Play"),
									new Button("Fonts\\CyrilicOld.TTF", "Choose Mission"),
									new Button("Fonts\\CyrilicOld.TTF", "Exit to Desktop") };
	main_menu = new MainMenu (e_Window.getSize().x, e_Window.getSize().y, main_menu_buttons);
	std::string title = std::string("MIPT DUNGEON MASTERS");
	main_menu->SetTitle(title);

	


	//Задание миссии 1
	std::vector <Button*> mission_menu_buttons = { new Button("Fonts\\CyrilicOld.TTF", "Continue mission"),
									new Button("Fonts\\CyrilicOld.TTF", "Restart"),
									new Button("Fonts\\CyrilicOld.TTF", "Exit to main menu") };
	MissionMenu* mission_menu = new MissionMenu(e_Window.getSize().x, e_Window.getSize().y, mission_menu_buttons);
	std::string src = std::string("images\\mission_menu_background.jpg");
	mission_menu->SetSprite(src);




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
	std::vector <Enemy*> enemies = { new Enemy(sf::Vector2f(350,100), sf::Vector2f(32 + 12,28),"knight","enemy","images\\roguelikeitems.png",IntRect(32*5-10, 32 * 14 - 10, 32 + 12, 32)),
									new Enemy(sf::Vector2f(100,200), sf::Vector2f(32 + 12,28),"knight","enemy","images\\roguelikeitems.png",IntRect(32*5-10, 32 * 14 - 10, 32 + 12, 32)),
									new Enemy(sf::Vector2f(350,200), sf::Vector2f(32 + 12,28),"Tkach","enemy","images\\roguelikeitems.png",IntRect(0, 32 * 16 - 20, 32 + 12, 28)) }; //IntRect(0, 32 * 16 - 20, 32 + 12, 28)
	enemies[2]->SetHealth(300);
	
	std::vector <MeleeWeapon*> m_weapons = { new MeleeWeapon(1500,100, 50, 20, sf::Vector2f(200,100), sf::Vector2f(32 + 14,32 + 10),"sword","m_weapon","images\\roguelikeitems.png",IntRect(0, 32 * 11-10, 32 + 14, 32+10)),
											new MeleeWeapon(2500,100, 55, 100, sf::Vector2f(300,200), sf::Vector2f(32 + 14,32 + 10),"axe","m_weapon","images\\roguelikeitems.png",IntRect(32*6, 32 * 11 - 10, 32 + 14, 32 + 10)) };
	enemies[1]->SetMeleeWeapon(m_weapons[1]);
	std::string m1_name = "Tutorial";
	Mission* m = new Mission(e_map, e_active,enemies,m_weapons,mission_menu,m1_name);
	Mission* r_m = m->save();
	mission = m;
	r_mission = r_m;
	



	Saves.push_back(std::make_pair(m, r_m));

	//Задание миссии 2
	mission_menu_buttons = { new Button("Fonts\\CyrilicOld.TTF", "Continue mission"),
									new Button("Fonts\\CyrilicOld.TTF", "Restart"),
									new Button("Fonts\\CyrilicOld.TTF", "Exit to main menu") };
	mission_menu = new MissionMenu(e_Window.getSize().x, e_Window.getSize().y, mission_menu_buttons);
	src = std::string("images\\mission_menu_background.jpg");
	mission_menu->SetSprite(src);




	e_active = new Player(sf::Vector2f(100, 100), sf::Vector2f(32 + 12, 32), "Player", "Mob", "images\\roguelikeitems.png", IntRect(0, 32 * 14 - 10, 32 + 12, 32));

	e_map = new Map();
	Tile = { "sssssssssssssss",
								 "sttttttttttttts",
								 "sttttttttttttts",
								 "sttttttttttttts",
								"sttttttttttttts",
								"sttttttttttttts",
								"sttttttttttttts",
								"sttttttttttttts",
								"sttttttttttttts",
								 "sssssssssssssss" };
	dict = { {'t',IntRect(0,0,32,32)},{'s',IntRect(32,0,32,32)} };
	e_map->SetMapLayers({ {"images\\default.png", dict , sf::Vector2f(32,32), Tile,sf::Vector2f(10,15) } }, sf::Vector2f(1000, 1000), sf::Vector2f(0, 0));
	e_map->SetMapObjects({ new Object(0,0,32,32 * 10, "wal","solid"),
							 new Object(0,32 * 9,32 * 15,32, "wal","solid"),
							 new Object(0,0,32 * 15,32,"wal","solid"),
							 new Object(32 * 14,0,32,32 * 10,"wal","solid")});
	enemies = { new Enemy(sf::Vector2f(350,100), sf::Vector2f(32 + 12,28),"knight","enemy","images\\roguelikeitems.png",IntRect(32 * 5 - 10, 32 * 14 - 10, 32 + 12, 32)),
									new Enemy(sf::Vector2f(100,200), sf::Vector2f(32 + 12,28),"knight","enemy","images\\roguelikeitems.png",IntRect(32 * 5 - 10, 32 * 14 - 10, 32 + 12, 32)) }; //IntRect(0, 32 * 16 - 20, 32 + 12, 28)
	

	m_weapons = { new MeleeWeapon(1500,100, 50, 20, sf::Vector2f(200,100), sf::Vector2f(32 + 14,32 + 10),"sword","m_weapon","images\\roguelikeitems.png",IntRect(0, 32 * 11 - 10, 32 + 14, 32 + 10)) };
	
	m1_name = "Mission 1";
	m = new Mission(e_map, e_active, enemies, m_weapons, mission_menu, m1_name);
	r_m = m->save();


	Saves.push_back(std::make_pair(m, r_m));
	

	std::vector<Button*> choice_menu_buttons;
	for (auto s : Saves) {
		choice_menu_buttons.push_back(new Button("Fonts\\CyrilicOld.TTF", s.first->GetName()));
	}
	choice_menu_buttons.push_back(new Button("Fonts\\CyrilicOld.TTF", "Exit"));
	choice_menu = new ChoiceMenu(e_Window.getSize().x, e_Window.getSize().y, choice_menu_buttons);
	src = std::string("images\\mission_menu_background.jpg");
	choice_menu->SetSprite(src);
	//Главный цикл движка
	while (e_Window.isOpen()) {

		float time_mcsec = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time_mcsec = time_mcsec/1000;
		input();
		update(time_mcsec);
		draw();
	}
	
}