#include <SFML/Graphics.hpp>
#include "Entity.h"

#define screen_width 1600
#define screen_hight 900

using namespace sf;

int Entity::update(float time) {
	return 0;
}

	FloatRect Entity::getRect() {
		return FloatRect(x, y, w, h);
	}
