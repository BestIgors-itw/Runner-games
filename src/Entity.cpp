#include <SFML/Graphics.hpp>
#include "Entity.h"

using namespace sf;

int Entity::update(float time) {
	return 0;
}

FloatRect Entity::getRect() {
	return FloatRect(x, y, w, h);
}
