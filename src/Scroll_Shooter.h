#pragma once

#include "SFML\Graphics.hpp"
#include <list>
#include <vector>
#include <sstream>
#include <ctime>
#include "Background.h"
#include "Bullets.h"
#include "Direction.h"
#include "Effects.h"
#include "Enemies_Cars.h"
#include "Entity.h"
#include "Interface.h"
#include "Player.h"

#define screen_width 1600
#define screen_hight 900

extern sf::Clock game_timer, animation_timer, background_timer, enemy_timer;

int Scroll_Shooter(sf::RenderWindow & window);