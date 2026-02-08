#pragma once
#include<random>

#include"EntityManager.h"

class SSpawner {

	unsigned int m_width;
	unsigned int m_height;
	EntityManager& m_entityManager;
	std::shared_ptr<Entity> m_player;

	std::default_random_engine m_randomEngine;

	std::uniform_int_distribution<int> m_randomInt;
	std::uniform_real_distribution<float> m_randomFloat;


public:

	SSpawner(EntityManager& m_entityManager);

	std::shared_ptr<Entity> player();
	void enemy();
	void miniEnemy();

	void randomizeInt(int min, int max);
	void randomizeFloat(float min, float max);
	int randomI();
	float randomF();

};