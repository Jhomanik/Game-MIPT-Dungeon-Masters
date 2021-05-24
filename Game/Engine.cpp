#include "Engine.h"

Engine::Engine() {
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	e_Window.create(VideoMode(resolution.x,resolution.y), "Game",Style::Fullscreen);
	mission = NULL;
	r_mission = NULL;
	is_mission = false;
	main_menu = NULL;
}



void Engine::start() {
	Clock clock;

	//Меню 
	std::vector <Button*> main_menu_buttons = { new Button ("Fonts\\CyrilicOld.ttf", "Play"),
									new Button("Fonts\\CyrilicOld.ttf", "Choose Mission"),
									new Button("Fonts\\CyrilicOld.ttf", "Exit to Desktop") };
	main_menu = new MainMenu (e_Window.getSize().x, e_Window.getSize().y, main_menu_buttons);
	std::string title = std::string("MIPT DUNGEON MASTERS");
	main_menu->SetTitle(title);

	


	//Задание миссии 1
	std::vector <Button*> mission_menu_buttons = { new Button("Fonts\\CyrilicOld.ttf", "Continue mission"),
		new Button("Fonts\\CyrilicOld.ttf", "Restart"),
		new Button("Fonts\\CyrilicOld.ttf", "Exit to main menu") };
	MissionMenu* mission_menu = new MissionMenu(e_Window.getSize().x, e_Window.getSize().y, mission_menu_buttons);
	std::string src = std::string("images\\mission_menu_background.jpg");
	mission_menu->SetSprite(src);



	//
	Player* e_active = new Player(sf::Vector2f(100, 95), sf::Vector2f(32 + 12, 32), "Player", "Mob", "images\\roguelikeitems.png", IntRect(0, 32 * 14 - 10, 32 + 12, 32));

	Map* e_map = new Map();
	std::vector <String> Tile = {
		"sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss",
		"sttttttttttttttttttttttttttttttttttttttttttttttttttttttttttss",
		"sttttttttttttttttttttttttttttttttttttttttttttttttttttttttttss",
		"sttttttttttttttttttttttttttttttttttttttttttttttttttttttttttss",
		"sssssssssssssssssstttssssssssssssssssssssssssssssssssttttttss",
		"oooooooooooooostttttttttsooooooooooooooooooooooooosttttttttss",
		"oooooooooooooostttttttttsooooooooooooooooooooooooosttttttttss",
		"oooooooooooooostttttttttsooooooooooooooooooooooooosttttttttss",
		"oooooooooooooostttttttttsooooooooooooooooooooooooosttttttttss",
		"oooooooooooooostttttttttsooooooooooooooooooooooooosttttttttss",
		"oooooooooooooosssssssssssooooooooooooooooooooooooosssssssssss" };
	std::map <char, IntRect> dict = { { 't',IntRect(0,0,32,32) },{ 's',IntRect(64,0,32,32) },{'o', IntRect(0,0,0,0)} };
	e_map->SetMapLayers({ { "images\\default.png", dict , sf::Vector2f(32,32), Tile,sf::Vector2f(11,62) } }, sf::Vector2f(1000, 1000), sf::Vector2f(0, 0));
	e_map->SetMapObjects({
		//new Object(0,0,32,32 * 11, "wal","solid"),
		new Object(0,0, 32, 32 * 11, "wall", "solid"),
		new Object(0,0, 32 * 65, 32, "wall", "solid"),
		new Object(0,32 * 11,32, 32 * 11, "wall", "solid"),
		new Object(0, 32 * 4, 32 * 18, 32, "wall", "solid"),
		new Object(32 * 21,32 * 4,32 * 32, 32, "wall", "solid"),
		new Object(32 * 59, 0, 32, 32 * 11, "wall", "solid"),
		new Object(32 * 14, 32 * 5, 32, 32 * 8, "wal", "solid"),
		new Object(32 * 24, 32 * 5, 32, 32 * 8, "wal", "solid"),
		new Object(0, 32 * 10, 32 * 65, 32, "wall", "solid"),
		new Object(32 * 50, 32 * 5, 32, 32 * 8, "wall", "solid")
		});
	std::vector <Enemy*> enemies = {  
	new Enemy(sf::Vector2f(300,70), sf::Vector2f(32 + 12,28),"knight","enemy","images\\roguelikeitems.png",IntRect(32 * 5 - 10, 32 * 14 - 10, 32 + 12, 32)),
	new Enemy(sf::Vector2f(1200,70), sf::Vector2f(32 + 12,28),"Tkach","enemy","images\\roguelikeitems.png",IntRect(32 * 5 - 10, 32 * 14 - 10, 32 + 12, 32)),
	new Enemy(sf::Vector2f(32 * 55,32 * 7), sf::Vector2f(32 + 12,28),"knight","enemy","images\\roguelikeitems.png",IntRect(32 * 5 - 10, 32 * 14 - 10, 32 + 12, 32)) }; //IntRect(0, 32 * 16 - 20, 32 + 12, 28)
	enemies[0]->SetHealth(30);
	enemies[0]->SetAgression(PEACEFULL);
	
	enemies[1]->SetHealth(30);
	enemies[1]->SetAgression(PEACEFULL);

	enemies[2]->SetHealth(100);
	

	std::vector <MeleeWeapon*> m_weapons = { new MeleeWeapon(1200,100, 50, 20, sf::Vector2f(32 * 18, 32 * 7), sf::Vector2f(32 + 14,32 + 10),"sword","m_weapon","images\\roguelikeitems.png",IntRect(0, 32 * 11 - 10, 32 + 14, 32 + 10)),
		new MeleeWeapon(2000,100, 55, 50, sf::Vector2f(300,200), sf::Vector2f(32 + 14,32 + 10),"axe","m_weapon","images\\roguelikeitems.png",IntRect(32 * 6, 32 * 11 - 10, 32 + 14, 32 + 10)) };
	enemies[1]->SetMeleeWeapon(m_weapons[1]);
	std::string  m1_name = "Tutorial";

	//
	Mission* m = new Mission(e_map, e_active, enemies, m_weapons, mission_menu, m1_name);
	Mission* r_m = m->save();
	mission = m;
	r_mission = r_m;
	Saves.push_back(std::make_pair(m, r_m));

	//Mission 2
	mission_menu_buttons = { new Button("Fonts\\CyrilicOld.TTF", "Continue mission"),
		new Button("Fonts\\CyrilicOld.TTF", "Restart"),
		new Button("Fonts\\CyrilicOld.TTF", "Exit to main menu") };
	mission_menu = new MissionMenu(e_Window.getSize().x, e_Window.getSize().y, mission_menu_buttons);
	src = std::string("images\\mission_menu_background.jpg");
	mission_menu->SetSprite(src);

	e_active = new Player(sf::Vector2f(100, 200), sf::Vector2f(32 + 12, 32), "Player", "Mob", "images\\roguelikeitems.png", IntRect(0, 32 * 14 - 10, 32 + 12, 32));

	e_map = new Map();
	Tile = {
		"ooooosssssssssssooooooooooooooossssssssssssssssssoooooooooooo",
		"ooooostttttttttsooooooooooooooosttttttttttttttttsoooooooooooo",
		"ooooostttttttttsooooooooooooooostttttsttttttttttsssssssssssss",
		"ooooostttttttttsooooooooooooooostttttsttttttttttsttttttttttss",
		"ooooostttttttttsooooooooooooooostttttsssssssttttsttttttttttss",
		"sssssstttttttttsssssssssssssssssttttttttttttttttsttttttttttss",
		"tttttttttttttttttttttttttttttttttttttttttttttttttttttttttttss",
		"tttttttttsssttttttttttttttttttttttttttttttttttttttttsttttttss",
		"ttttttttttttttttttttttttttttttttttttttttttttttttttttsttttttss",
		"sssssstttttttttssssssstttsssssssttttttssssssstttsttttttttttss",
		"ooooostttttttttsooooostttsooooosttttttttttttstttstttttsssttss",
		"ooooostttttttttsooooostttsooooosttttttttttttstttsttttttttttss",
		"ooooostttttttttsooooostttsooooosttttttttttttttttsttttttttttss",
		"ooooostttttttttsooooostttsooooosttttttttttttttttsttttttttttss",
		"ooooosssssssssssooooostttsooooossssssssssssssssssttttttttttss",
		"ooooooooooooooooooooostttsoooooooooooooooooooooossstttsssssss",
		"ooooooooooooooooooooostttsoooooooooooooooooooooooostttsoooooo",
		"ooooooooossssssssssssstttsssssssssssssssssssssssssstttsoooooo",
		"ooooooooosttttttttttttttttttttttttttttttttttttttttttttsoooooo",
		"ooooooooosttttttttttttttttttttttttttttttttttttttttttttsoooooo",
		"ooooooooostttttttttttttttssssssssssssssssssssssssssssssoooooo",
		"ooooooooostttttttttttttttsooooooooooooooooooooooooooooooooooo",
		"ooooooooostttttttttttttttsooooooooooooooooooooooooooooooooooo",
		"ooooooooosssssssssssssssssooooooooooooooooooooooooooooooooooo" };
	dict = { { 't',IntRect(0,0,32,32) },{ 's',IntRect(64,0,32,32) },{ 'o', IntRect(0,0,0,0) } };
	e_map->SetMapLayers({ { "images\\default.png", dict , sf::Vector2f(32,32), Tile,sf::Vector2f(24,62) } }, sf::Vector2f(1000, 1000), sf::Vector2f(0, 0));
	e_map->SetMapObjects({
		//new Object(0,0,32,32 * 11, "wal","solid"),
		new Object(32 * 5, 0, 32 * 11, 32, "wall", "solid"),
		new Object(32 * 31, 0, 32 * 18, 32, "wall", "solid"),
		new Object(32 * 48, 32 * 2, 32 * 13, 32, "wal", "solid"),
		new Object(0, 32 * 5, 32 * 5, 32, "wall", "solid"),
		new Object(32 * 15, 32 * 5, 32 * 17, 32, "wall", "solid"),
		new Object(32 * 38, 32 * 4, 32 * 6, 32,"wall", "solid"),
		new Object(0, 32 * 9, 32 * 5, 32, "wall", "solid"),
		new Object(32 * 9, 32 * 7, 32 * 3, 32,"wall", "solid"),
		new Object(32 * 5, 32 * 14, 32 * 11, 32, "wall", "solid"),
		new Object(32 * 15, 32 * 9, 32 * 7, 32 ,"wall", "solid"),
		new Object(32 * 9, 32 * 17, 32 * 13, 32,"wall", "solid"),
		new Object(32 * 25, 32 * 17, 32 * 26, 32,"wall", "solid"),
		new Object(32 * 9, 32 * 23, 32 * 17, 32 ,"wall", "solid"),
		new Object(32 * 25, 32 * 20, 32 * 30, 32,"wall", "solid"),
		new Object(32 * 25, 32 * 9, 32 * 7, 32, "wall", "solid"),
		new Object(32 * 38, 32 * 9, 32 * 7, 32,"wall", "solid"),
		new Object(32 * 31, 32 * 14, 32 * 18, 32, "wall", "solid"),
		new Object(32 * 48, 32 * 15, 32 * 3, 32, "wall", "solid"),
		new Object(32 * 54, 32 * 15, 32 * 3, 32, "wall", "solid"),
		new Object(32 * 54, 32 * 10, 32 * 3, 32, "wall", "solid"),
		new Object(0, 32 * 5, 32, 32 * 5, "wall", "solid"),			
		new Object(32 * 5, 0, 32, 32 * 5, "wall", "solid"),
		new Object(32 * 5, 32 * 9, 32, 32 * 5, "wall", "solid"),
		new Object(32 * 15, 0, 32, 32 * 5, "wall", "solid"),
		new Object(32 * 15, 32 * 9, 32, 32 * 5, "wall", "solid"),
		new Object(32 * 9, 32 * 17, 32, 32 * 7, "wall", "solid"),
		new Object(32 * 25, 32 * 21, 32, 32 * 4, "wall", "solid"),
		new Object(32 * 21, 32 * 9, 32, 32 * 9, "wall", "solid"),
		new Object(32 * 25, 32 * 9, 32, 32 * 9, "wall", "solid"),
		new Object(32 * 31, 0, 32, 32 * 6, "wall", "solid"),
		new Object(32 * 48, 0, 32, 32 * 6, "wall", "solid"),
		new Object(32 * 31, 32 * 9, 32, 32 * 6, "wall", "solid"),
		new Object(32 * 48, 32 * 9, 32, 32 * 6, "wall", "solid"),
		new Object(32 * 37, 32 * 2, 32, 32 * 3, "wall", "solid"),
		new Object(32 * 44, 32 * 9, 32, 32 * 3, "wall", "solid"),
		new Object(32 * 52, 32 * 7, 32, 32 * 2, "wall", "solid"),
		new Object(32 * 59, 0, 32, 32 * 24,"wall", "solid"),
		new Object(32 * 54, 32 * 15, 32, 32 * 7, "wall", "solid")
		});
	enemies = { new Enemy(sf::Vector2f(32 * 9,32 * 2), sf::Vector2f(32 + 12,28),"knight","enemy","images\\roguelikeitems.png",IntRect(32 * 5 - 10, 32 * 14 - 10, 32 + 12, 32)),
	new Enemy(sf::Vector2f(32 * 54,32 * 7), sf::Vector2f(32 + 12,28),"tkach","enemy","images\\roguelikeitems.png",IntRect(0, 32 * 16 - 20, 32 + 12, 28)),
	new Enemy(sf::Vector2f(32 * 9,32 * 11), sf::Vector2f(32 + 12,28),"knight","enemy","images\\roguelikeitems.png",IntRect(32 * 5 - 10, 32 * 14 - 10, 32 + 12, 32)),
	new Enemy(sf::Vector2f(32 * 40,32 * 2), sf::Vector2f(32 + 12,28),"knight","enemy","images\\roguelikeitems.png",IntRect(32 * 5 - 10, 32 * 14 - 10, 32 + 12, 32)),
	new Enemy(sf::Vector2f(32 * 41,32 * 11), sf::Vector2f(32 + 12,28),"knight","enemy","images\\roguelikeitems.png",IntRect(32 * 5 - 10, 32 * 14 - 10, 32 + 12, 32)),
	new Enemy(sf::Vector2f(32 * 18,32 * 21), sf::Vector2f(32 + 12,28),"tkach","enemy","images\\roguelikeitems.png",IntRect(0, 32 * 16 - 20, 32 + 12, 28)),
	}; //IntRect(0, 32 * 16 - 20, 32 + 12, 28)
	enemies[0]->SetHealth(300);

	m_weapons = { new MeleeWeapon(1500,100, 50, 20, sf::Vector2f(32 * 18, 32 * 7), sf::Vector2f(32 + 14,32 + 10),"sword","m_weapon","images\\roguelikeitems.png",IntRect(0, 32 * 11 - 10, 32 + 14, 32 + 10)),
		new MeleeWeapon(2500,100, 55, 100, sf::Vector2f(300,200), sf::Vector2f(32 + 14,32 + 10),"axe","m_weapon","images\\roguelikeitems.png",IntRect(32 * 6, 32 * 11 - 10, 32 + 14, 32 + 10)),
		new MeleeWeapon(200,100, 250, 20, sf::Vector2f(32 * 16,32 * 20), sf::Vector2f(32 + 14,32 + 10),"wabbajack","m_weapon","images\\roguelikeitems.png",IntRect(147, 528, 32 + 14, 32 + 10)),
		new MeleeWeapon(1500,100, 50, 20, sf::Vector2f(32 * 18, 32 * 7), sf::Vector2f(32 + 14,32 + 10),"sword","m_weapon","images\\roguelikeitems.png",IntRect(0, 32 * 11 - 10, 32 + 14, 32 + 10)),
		new MeleeWeapon(1500,100, 50, 20, sf::Vector2f(32 * 18, 32 * 7), sf::Vector2f(32 + 14,32 + 10),"sword","m_weapon","images\\roguelikeitems.png",IntRect(0, 32 * 11 - 10, 32 + 14, 32 + 10)),
		new MeleeWeapon(1500,100, 50, 20, sf::Vector2f(32 * 18, 32 * 7), sf::Vector2f(32 + 14,32 + 10),"sword","m_weapon","images\\roguelikeitems.png",IntRect(0, 32 * 11 - 10, 32 + 14, 32 + 10)),
		new MeleeWeapon(1500,100, 50, 20, sf::Vector2f(32 * 18, 32 * 7), sf::Vector2f(32 + 14,32 + 10),"sword","m_weapon","images\\roguelikeitems.png",IntRect(0, 32 * 11 - 10, 32 + 14, 32 + 10)),
		new MeleeWeapon(1500,100, 50, 10, sf::Vector2f(32 * 34, 32 * 18), sf::Vector2f(32 + 14,32 + 10),"ring","m_weapon","images\\roguelikeitems.png",IntRect(193, 99, 32 + 14, 32 + 10)),
	};
	m_weapons[7]->SetRecoil(1000);
	enemies[1]->SetMeleeWeapon(m_weapons[1]);
	enemies[2]->SetMeleeWeapon(m_weapons[6]);
	enemies[3]->SetMeleeWeapon(m_weapons[3]);
	enemies[4]->SetMeleeWeapon(m_weapons[4]);
	enemies[0]->SetMeleeWeapon(m_weapons[5]);
	enemies[5]->SetMeleeWeapon(m_weapons[1]);
	m1_name = "Mission 1";

	//
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