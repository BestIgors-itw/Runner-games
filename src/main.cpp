#include <iostream> 
#include <SFML/Graphics.hpp>
#include "Player.h"


using namespace sf;

int main()
{
	RenderWindow window(sf::VideoMode(1600, 900), "ScrollShooter", Style::Fullscreen);

	Clock clock;

	Player p("car1.png", 750, 650, 50, 100, 0.5);

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		if ((Keyboard::isKeyPressed(Keyboard::Escape))) {
			window.close();
		}

		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
			p.dir = 1; p.speed = 0.5;
			p.sprite.setRotation(-2.5);
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
			p.dir = 0; p.speed = 0.5;
			p.sprite.setRotation(2.5);
		}

		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
			p.dir = 3; p.speed = 0.5;
		}

		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
			p.dir = 2; p.speed = 0.5;
		}

		if (!(Keyboard::isKeyPressed(Keyboard::Right)) && !(Keyboard::isKeyPressed(Keyboard::Left))) {
			p.sprite.setRotation(0); p.speed = 0.5;
		}

		p.update(time);

		window.clear();
		window.draw(p.sprite);
		window.display();
	}

	return 0;
}