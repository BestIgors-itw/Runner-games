#include "Entity.h"

int Entity::update(float time) {
	return 0;
}

sf::FloatRect Entity::get_rect() {
	return sf::FloatRect(x, y, w, h);
}

bool Entity::is_alive() {
	return alive;
}

unsigned short int Entity::get_w() {
	return w;
}

unsigned short int Entity::get_h() {
	return h;
}

float Entity::get_x() {
	return x;
}

float Entity::get_y() {
	return y;
}

sf::Sprite Entity::get_sprite() {
	return sprite;
}

void Entity::kill_object() {
	alive = false;
}
