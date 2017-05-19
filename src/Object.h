#pragma once

using namespace sf;

class Object :public Entity {
public:
	Object::Object(Image &image, float X, float Y, int W, int H, float Speed, float Health, String Name)
		:Entity(image, X, Y, W, H, Speed, Health, Name) {
		if (name == "Background") {
			dy = speed;
		}
	}

	void update(float time);
};