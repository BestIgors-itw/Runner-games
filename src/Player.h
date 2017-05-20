#pragma once

#include "Entity.h"

using namespace sf;

class Player : public Entity
{
  public:
    float score;

	Player::Player(Image &image, float X, float Y, int W, int H, float Speed, float Health, String Name)
		: Entity(image, X, Y, W, H, Speed, Health, Name), score(0.0) {};

    void control();
    int update(float time);
};
