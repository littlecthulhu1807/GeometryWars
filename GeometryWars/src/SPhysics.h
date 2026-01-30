#pragma once

#include"EntityManager.h"
#include<SFML/Graphics.hpp>

class SPhysics {

public:
	bool physicsCalc = true;
	void updateMovement(EntityManager& entityM, int width, int height);

	void updatePlayer(EntityManager& entityM);
	void updateEnemyType(EntityManager& entityM, int width, int height);
};