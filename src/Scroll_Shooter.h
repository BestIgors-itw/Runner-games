#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <sstream>
#include <ctime>
#include "Background.h"
#include "Bullet.h"
#include "Direction.h"
#include "Effect.h"
#include "Scroll_Shooter_Enemies_Car.h"
#include "Entity.h"
#include "Interface.h"
#include "Player.h"

extern sf::Clock game_timer, Compensating_for_performance_losses_timer, background_timer, enemy_timer;

int Scroll_Shooter(sf::RenderWindow & window);