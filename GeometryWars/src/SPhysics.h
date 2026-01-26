#pragma once

#include"EntityManager.h"

class SPhysics {

	bool m_physicsCalc = true;

public:
	void updateMovement(EntityManager& entityM, int height, int width);

	void setPhysicsCalc(bool setP);
	bool getPhysicsCalc();
};