#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Object.h"

using namespace sf;

class Object :public Entity {
public:
	Object::Object(Image &image, float X, float Y, int W, int H, float Speed, float Health, String Name) :Entity(image, X, Y, W, H, Speed, Health, Name) {
		if (name == "Background") {
			dx = -0.6;
		}
		if (name == "Effect") {
			dx = -0.6;
		}
		if (name == "Enemy") {
			dx = speed;
		}
	};

	int update(float time);
};