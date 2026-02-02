#pragma once
#include"EntityManager.h"
#include"math.h"

class SCollision {

	EntityManager& m_entityManager;

public:

	SCollision(EntityManager& entityManager);

	void checkCollision();

};