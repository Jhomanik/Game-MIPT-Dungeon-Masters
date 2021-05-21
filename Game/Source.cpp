#include "Bullet.h"
#include<iostream>

Bullet::Bullet() :Object() {
	//Перчаточка

	bul_dir = STOP;

	image.loadFromFile("images\FireBall.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setPosition(position);
}

void Bullet::draw(sf::RenderWindow* window) {
	
	window->draw(sprite);
	
}