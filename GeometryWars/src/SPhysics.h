#pragma once

#include"EntityManager.h"

class SPhysics {

	bool m_physicsCalc = true;

public:
	void updateMovement(EntityManager& entityM, int width, int height);

	void setPhysicsCalc(bool setP);
	bool getPhysicsCalc();
};