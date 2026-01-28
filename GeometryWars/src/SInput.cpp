#include"SInput.h"

SInput::SInput(){
}

void SInput::matchKeyInput(sf::Keyboard::Scancode keypress, SRender& renderer, SPhysics& physics, EntityManager& entityManager){
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
		
	case sf::Keyboard::Scancode::W:
		for (auto e : entityManager.getEntities("player")) {
			if (e->get<CInput>().exists) {
				CTransform& tempTrans = e->get<CTransform>();

				tempTrans.setPos({ tempTrans.getPos().x,  tempTrans.getPos().y - tempTrans.getVel() });
			}
		}
		break;
	case sf::Keyboard::Scancode::A:
		for (auto e : entityManager.getEntities("player")) {
			if (e->get<CInput>().exists) {
				CTransform& tempTrans = e->get<CTransform>();

				tempTrans.setPos({ tempTrans.getPos().x - tempTrans.getVel(),  tempTrans.getPos().y });
			}
		}
		break;
	case sf::Keyboard::Scancode::S:
		for (auto e : entityManager.getEntities("player")) {
			if (e->get<CInput>().exists) {
				CTransform& tempTrans = e->get<CTransform>();

				tempTrans.setPos({ tempTrans.getPos().x,  tempTrans.getPos().y + tempTrans.getVel() });
			}
		}
		break;
	case sf::Keyboard::Scancode::D:
		for (auto e : entityManager.getEntities("player")) {
			if (e->get<CInput>().exists) {
				CTransform& tempTrans = e->get<CTransform>();

				tempTrans.setPos({ tempTrans.getPos().x + tempTrans.getVel(),  tempTrans.getPos().y });
			}
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
