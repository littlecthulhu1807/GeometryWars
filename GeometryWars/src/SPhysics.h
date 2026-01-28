#pragma once

#include"EntityManager.h"
#include<SFML/Graphics.hpp>

class SPhysics {

	bool m_physicsCalc = true;

public:
	void updateMovement(EntityManager& entityM, int width, int height);

	void setPhysicsCalc(bool setP);
	bool getPhysicsCalc();

	void updatePlayer(EntityManager& entityM);
	void updateEntityType(EntityManager& entityM, std::string entityKey, int width, int height);
};