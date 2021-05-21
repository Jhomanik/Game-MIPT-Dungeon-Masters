#include "Object.h"

typedef enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	STOP
}m_dir_state;

class Bullet : public Object
{
private:

protected:
	float bul_speed = 0.8;
	m_dir_state bul_dir;
	int sprite_width = 64;
	int sprite_height = 64;
	float default_pos_x = 5000;
	float default_pos_y = 5000;
	float damage = 49.5;


public:
	Bullet();
	Bullet(float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	Bullet(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	Bullet(const Bullet& m);

	//setter для показателей
	void SetSprite(std::string src, sf::IntRect frameRect);
	void SetSpeed(float speed);
	void TakeDamage(float damage, sf::Vector2f damage_dir, float attack_duration);
	void SetDiraction(m_dir_state dir);


	//Рисование и обновление позиций игрока
	void draw(sf::RenderWindow* window);
	sf::RectangleShape GetAttackShape();

	void CheckCollisionsWithMap(std::vector<Object*>& solid, float Dx, float Dy);
	void CheckCollisionsWithMob(std::vector<Object*>& solid, float Dx, float Dy);


	template <class T>
	void  attack(std::vector <T*>& enemies) {
		if (active_melee_weapon->GetState()) {
			float attack_rad = 3;
			float attack_damage = 49.5;

			attack_rect = sf::FloatRect(position.x + size.x / 2 - attack_rad, position.y + size.y / 2 - attack_rad, 2 * attack_rad, 2 * attack_rad);
			for (auto enemy : enemies) {
				if (attack_rect.intersects(enemy->GetRect())) {
					enemy->TakeDamage(attack_damage, position + sf::Vector2f(size.x / 2, size.y / 2), attack_damage / 10 * 100);
				}
				else {
					delete Bullet
				}
			}
		}
	}
};
