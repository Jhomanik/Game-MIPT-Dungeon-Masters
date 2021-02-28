#include "Engine.h"
Engine::Engine() {
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	e_Window.create(VideoMode(resolution.x,resolution.y), "Game",Style::Fullscreen);
	background_image.loadFromFile("images\\swamp.png");
	background_texture.loadFromImage(background_image);
	background_sprite.setTexture(background_texture);
	e_active = nullptr;
	e_map = nullptr;
	
}
void Engine::start() {
	Clock clock;
	Map map_1;
	Mob Player;

	Player.Set_position(Vector2f(100, 100));
	Player.Set_texture("images\\roguelikeitems.png", IntRect(0, 32*14 -10 ,32+12, 32));
	std::vector <String> Tile = { "ssssssssss",
								 "sttttsssts",
								 "sttstststs",
								 "sttsssttts",
								 "ssssssssss" };
	std::map <char, IntRect> dict = { {'t',IntRect(0,0,32,32)},{'s',IntRect(32,0,32,32)} };
	map_1.Set_tile(Tile, 5, 10);
	map_1.Set_sprite("images\\default.png", dict, 32);

	e_active = &Player;
	e_map = &map_1;
	while (e_Window.isOpen()) {

		float time_mcsec = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time_mcsec = time_mcsec / 1000;
		input();
		update(time_mcsec);
		draw();
	}
}