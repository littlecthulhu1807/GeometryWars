#pragma once
#include"SRender.h"
#include"SPhysics.h"
#include<SFML/Window/Event.hpp>

class SInput {


public:
	SInput();
	void matchKeyInput(sf::Keyboard::Scancode keypress, SRender& renderer, SPhysics& physics);
	void matchMouseInput(sf::Mouse::Button button);

};
