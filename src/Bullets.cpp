#include "Entity.h"
#include "Bullets.h"
#include "Direction.h"

#define screen_width 1600
#define screen_hight 900

int Bullets::update(float time) {
	x += dx * time;
	y += dy * time;
	sprite.setPosition(x, y);
	if (x - 20 < 0 || x > screen_width + 20 || y - 20 < 0 || y > screen_hight + 20) {
		life = false;
	}
	return 0;
}