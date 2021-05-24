#include "Object.h"
Object::Object(float left, float top, float w, float h, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect) {
	position = sf::Vector2f(left, top);
	size = sf::Vector2f(w, h);
	name = o_name;
	type = o_type;
	image.loadFromFile(sprite_src);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(frameRect);
	sprite.setPosition(position);
}
Object::Object(float left, float top, float w, float h, std::string o_name, std::string o_type) {
	position = sf::Vector2f(left, top);
	size = sf::Vector2f(w, h);
	name = o_name;
	type = o_type;
	
	sprite.setPosition(position);
}
Object::Object(sf::Vector2f pos, sf::Vector2f siz, std::string o_name, std::string o_type, std::string sprite_src, sf::IntRect frameRect) {
	position = pos;
	size = siz;
	name = o_name;
	type = o_type;
	spr_source = sprite_src;
	frame_rect = frameRect;
	image.loadFromFile(sprite_src);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(frameRect);
	sprite.setPosition(position);
}

Object::Object(sf::Vector2f pos, sf::Vector2f siz, std::string o_name, std::string o_type) {
	position = pos;
	size = siz;
	name = o_name;
	type = o_type;
	sprite.setPosition(position);
}
Object::Object() {

	position = sf::Vector2f(0, 0);
	size = sf::Vector2f(1, 1);

}


void Object::SetObject(sf::Vector2f pos, sf::Vector2f size, std::string o_name, std::string o_type) {
	position = pos;
	size = size;
	name = o_name;
	type = o_type;
}
void Object::SetObject(float left, float top, float w, float h, std::string o_name, std::string o_type) {
	position = sf::Vector2f(left, top);
	size = sf::Vector2f(w, h);
	name = o_name;
	type = o_type;
}
void Object::SetPosition(sf::Vector2f pos) {
	position = pos;

}

void Object::SetSize(sf::Vector2f s) {
	size = s;
}
void Object::SetType(std::string o_type) {
	type = o_type;
}
void Object::SetName(std::string o_name) {
	name = o_name;
}
void Object::SetSprite(std::string src, sf::IntRect frameRect) {
	image.loadFromFile(src);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(frameRect);
	size = sf::Vector2f(frameRect.height, frameRect.width);
	spr_source = src;
	frame_rect = frameRect;
}


sf::Vector2f Object::GetPos() {
	return position;
}
sf::Vector2f Object::GetSize() {
	return size;
}
sf::Sprite Object::GetSprite() {
	return sprite;
}
sf::FloatRect Object::GetRect() {
	return sf::FloatRect(position.x, position.y, size.x, size.y);
}

std::string Object::GetType() {
	return type;
}
std::string Object::GetName() {
	return name;
}