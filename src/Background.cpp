#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Background.h"

#define screen_width 1600
#define screen_hight 900

	int Background::update(float time) {
		y += dy * time;
		sprite.setPosition(x, y);
		if (y > screen_hight) {
			life = false;
		}
		return 0;
	}