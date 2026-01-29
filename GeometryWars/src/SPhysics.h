#pragma once

#include"EntityManager.h"
#include<SFML/Graphics.hpp>

class SPhysics {

	

public:
	bool m_physicsCalc = true;
	void updateMovement(EntityManager& entityM, int width, int height);

	void setPhysicsCalc(bool setP);
	bool getPhysicsCalc();

	void updatePlayer(EntityManager& entityM);
	void updateEnemyType(EntityManager& entityM, int width, int height);
};