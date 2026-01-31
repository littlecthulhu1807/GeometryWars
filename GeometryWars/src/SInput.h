#pragma once
#include"SRender.h"
#include"SPhysics.h"
#include<SFML/Window/Event.hpp>

#include<iostream>

class SInput {


public:
	SInput();
	void matchKeyInput(sf::Keyboard::Scancode keypress, SRender& renderer, SPhysics& physics, EntityManager& entityManager);
	void matchKeyRelease(sf::Keyboard::Scancode keyprelease, EntityManager& entityManager);
	void matchMouseInput(sf::Mouse::Button button, sf::Vector2i targetPos, EntityManager& entityManager);
	

};
