#include "Entity.h"

int Entity::update(float time) {
	return 0;
}

sf::FloatRect Entity::getRect() {
	return sf::FloatRect(x, y, w, h);
}