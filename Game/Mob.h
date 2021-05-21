#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "MeleeWeapon.h"


using namespace sf;
typedef enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	STOP
}m_dir_state;

typedef enum {
	TAKE,
	SWAP,
	DROP,
	NOTHING
} m_mweapon_state;

class Mob: public Object, public updatable, public drawable{
private:

protected:
	//Характеристики скорости, здоровья и направления движения
	float m_speed = 0.4;
	float m_health;
	m_dir_state m_dir;
	m_mweapon_state mweapon_state = NOTHING;
	bool is_life;
	//Принимаемый урон
	float recoil_timer = 0;
	sf::Vector2f recoil_dir;
	float immortal_timer = 0;

	sf::Sprite glove;
	sf::Image glove_image;
	sf::Texture glove_texture;
	

	//Оружие
	MeleeWeapon* hands;
	MeleeWeapon* m_weapon;
	MeleeWeapon* active_melee_weapon ;
	sf::FloatRect attack_rect;

	//Взаимодействие с предметами
	float interaction_rad = 30;
	

public:
	//Конструктор
	Mob();
	//Здесь по факту w и h задаются framerect,но для каноничноти я их не убрал, поэтому смотрите что в конструкторах задаёте одинаково
	Mob(float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	Mob(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect);
	Mob(const Mob& m);
	
	//setter для показателей
	void SetSprite(std::string src, sf::IntRect frameRect);
	void SetSpeed(float speed);
	void SetHealth(float health);
	void SetLife(bool life);
	void SetDiraction(m_dir_state dir);
	void SetMobParams(float  speed, float health);
	void SetMeleeWeapon(MeleeWeapon* melee_weapon);

	float GetHealth();
	void Kill();
	void TakeDamage(float damage, sf::Vector2f damage_dir, float attack_duration);
	void SwapMeleeWeapon();
	void DropMeleeWeapon();
	MeleeWeapon* GetMW();
	bool GetIsLife();
	//Рисование и обновление позиций игрока
	void draw(sf::RenderWindow* window);
	sf::RectangleShape GetAttackShape();

	
	

	//optimize it Нужно для проверки столкновения моба с картой
	void CheckCollisionsWithMap(std::vector<Object*>& solid, float Dx, float Dy);

	template <class T>
	void  attack(std::vector <T*>& enemies) {
		if (active_melee_weapon->GetState() == ATTACK) {
			float attack_rad = active_melee_weapon->GetRad();
			float attack_damage = active_melee_weapon->GetDamage();
			
			attack_rect = sf::FloatRect(position.x + size.x / 2 - attack_rad, position.y + size.y / 2 - attack_rad, 2 * attack_rad, 2 * attack_rad);
			for (auto enemy : enemies) {
				if (attack_rect.intersects(enemy->GetRect())) {
					enemy->TakeDamage(attack_damage, position + sf::Vector2f(size.x / 2, size.y / 2), attack_damage / 10 * 100);
				}
			}
		}
	}

	template <class T>
	T* TakeItem(std::vector <T*> items) {
		sf::FloatRect interaction_rect = sf::FloatRect(position.x + size.x / 2 - interaction_rad, position.y + size.y / 2 - interaction_rad, 2 * interaction_rad, 2 * interaction_rad);

		for (auto item : items) {
			if (interaction_rect.intersects(item->GetRect()) && !item->GetWithMob()) {
				return item;
			}	
		}
		return nullptr;
	}

	
	
};