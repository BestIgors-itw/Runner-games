#include "Images.h"

int Inicialisation() {
	if (!background_i.loadFromFile("res/images/menu/menuback.png")) {
		return 1;
	}

	background_t.loadFromImage(background_i);

	background_s.setTexture(background_t);

	if (!button_i.loadFromFile("res/images/interface/button.png")) {
		return 1;
	}

	button_t.loadFromImage(button_i);

	button_s.setTexture(button_t);

	return 0;
}