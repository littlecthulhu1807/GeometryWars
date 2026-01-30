#include"SInput.h"

SInput::SInput(){
}

void SInput::matchKeyInput(sf::Keyboard::Scancode keypress, SRender& renderer, SPhysics& physics, EntityManager& entityManager){
	switch (keypress) {
		//GeneralInputs ->
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
		if (physics.physicsCalc) {
			physics.physicsCalc = false;
		}
		else {
			physics.physicsCalc = true;
		}
		break;
		//MovementInputs ->
	case sf::Keyboard::Scancode::W:
		for (auto e : entityManager.getEntities("player")) {
			e->get<CInput>().up = true;
		}
		break;
	case sf::Keyboard::Scancode::A:
		for (auto e : entityManager.getEntities("player")) {
			e->get<CInput>().left = true;
		}
		break;
	case sf::Keyboard::Scancode::S:
		for (auto e : entityManager.getEntities("player")) {
			e->get<CInput>().down = true;
		}
		break;
	case sf::Keyboard::Scancode::D:
		for (auto e : entityManager.getEntities("player")) {
			e->get<CInput>().right = true;
		}
		break;
		
	}
}

void SInput::matchKeyRelease(sf::Keyboard::Scancode keyprelease, EntityManager& entityManager){
	switch (keyprelease) {
	case sf::Keyboard::Scancode::W:
		for (auto e : entityManager.getEntities("player")) {
			e->get<CInput>().up = false;
		}
		break;
	case sf::Keyboard::Scancode::A:
		for (auto e : entityManager.getEntities("player")) {
			e->get<CInput>().left = false;
		}
		break;
	case sf::Keyboard::Scancode::S:
		for (auto e : entityManager.getEntities("player")) {
			e->get<CInput>().down = false;
		}
		break;
	case sf::Keyboard::Scancode::D:
		for (auto e : entityManager.getEntities("player")) {
			e->get<CInput>().right = false;
		}
		break;
	}
}

void SInput::matchMouseInput(sf::Mouse::Button button) {
	switch (button){
	case sf::Mouse::Button::Left:
		std::cout << "Left Mouse! Attack!\n";
		break;
	case sf::Mouse::Button::Right:
		std::cout << "Right Mouse! Special Attack\n";
		break;
	}
}
