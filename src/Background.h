#include "Entity.h"
#pragma once

using namespace sf;

class Background : public Entity {
public:
	Background::Background(Image &image, float X, float Y, int W, int H) :Entity(image, X, Y, W, H) {
		dx = -0.6;
	}
	int update(float time);
};