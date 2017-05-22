#include "Entity.h"
#include "Background.h"

using namespace sf;

	int Background::update(float time) {
		x += dx * time;
		sprite.setPosition(x, y);
		if (x + w < 0) {
			life = false;
		}
		return 0;
	}