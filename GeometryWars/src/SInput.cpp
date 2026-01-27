#include"SInput.h"
#include<iostream>

SInput::SInput(){
}

void SInput::matchKeyInput(sf::Keyboard::Scancode keypress, SRender& renderer, SPhysics& physics){
	switch (keypress) {
	case sf::Keyboard::Scancode::Escape:
		renderer.getWindow().close();
		break;
	case sf::Keyboard::Scancode::R:
		if (renderer.getRendering()) {
			renderer.setRendering(false);
		}
		else {
			renderer.setRendering(true);
		}
		break;
	case sf::Keyboard::Scancode::M:
		if (physics.getPhysicsCalc()) {
			physics.setPhysicsCalc(false);
		}
		else {
			physics.setPhysicsCalc(true);
		}
		break;
	}
}

void SInput::matchMouseInput(sf::Mouse::Button button) {
	switch (button){
	case sf::Mouse::Button::Left:
		std::cout << "Left Mouse!\n";
		break;
	case sf::Mouse::Button::Right:
		std::cout << "Right Mouse!\n";
		break;
	}
}
