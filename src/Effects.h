#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Direction.h"

using namespace sf;

extern Clock clock1, game_timer, background_timer, enemy_timer;

class Effects : public Entity {
public:
	float timer, exist_time, dx, dy;
	Effects::Effects(Image &image, float X, float Y, int W, int H, float Speed, float Direction, float Exist_time) :Entity(image, X, Y, W, H) {
		Direction_convert(Direction, dx, dy, Speed);
		timer = game_timer.getElapsedTime().asSeconds();
		exist_time = Exist_time;
	};
	
	int update(float time);
};