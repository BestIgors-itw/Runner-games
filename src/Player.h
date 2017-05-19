#pragma once

using namespace sf;

class Player :public Entity {
public:
	int playerScore;

	Player(Image &image, float X, float Y, int W, int H, float Speed, float Health, String Name) :Entity(image, X, Y, W, H, Speed, Health, Name) {
		playerScore = 0;
	}

	void control(void);

	void update(float time);
};