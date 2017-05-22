#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Interface : public Entity {
public:
	Interface(Image &image, float X, float Y, int W, int H) :Entity(image, X, Y, W, H) {};

	int update(float time);
};