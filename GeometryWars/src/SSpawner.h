#pragma once
#include"EntityManager.h"




class SSpawner {

	EntityManager& m_entityManager;

public:

	enum entityType {
		payer,
		bullet,
		enemy
	};


	SSpawner(EntityManager& entityManager);

	void spawn();
	void remove();

};
