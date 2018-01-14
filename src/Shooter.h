#pragma once

#include <SFML/Graphics.hpp>
#include <list>
#include <sstream>
#include <ctime>
#include "Background.h"
#include "Direction.h"
#include "Effect.h"
#include "Shooter_enemies_car.h"
#include "Entity.h"
#include "Interface.h"
#include "Player.h"

extern sf::Clock game_timer, Compensating_for_performance_losses_timer, background_timer, enemy_timer;

int Shooter(sf::RenderWindow & window);
