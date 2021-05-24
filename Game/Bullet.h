#include "Object.h"
#include "Player.h"


class Bullet : public Object
{
private:

protected:
	float bul_speed = 0.12;
	sf::Vector2f bul_dir = sf::Vector2f(0, 0);
	float damage = 15;
	bool is_destroy = false;


public:
	Bullet();
	Bullet(float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	Bullet(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	

	//setter для показателей
	void SetSpeed(float speed);
	void SetDiraction(sf::Vector2f dir);

	bool GetState();

	

	

	void CheckCollision(std::vector <Object*> solid, Player* p);
	Bullet* copy();

	void update(std::vector <Object*> solid, Player* p, float elapsed_time);
	void draw(sf::RenderWindow* window);




};
