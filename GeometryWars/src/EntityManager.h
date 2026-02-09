#pragma once

#include"Entity.h"

#include<memory> 
#include<iostream>
#include<string>
#include <vector>
#include<algorithm>
#include<map>
#include<random>

using EntityVec = std::vector<std::shared_ptr<Entity>>;
using EntityMap = std::map<std::string, EntityVec>;

class EntityManager{

	EntityVec m_EntityVec; //std::Vector of Enteties
	EntityMap m_entityMap; //std::map of entities with tags
	EntityVec m_toAdd; //Std::Vector of entities to add for next frame
	EntityVec m_toRemove; //Std::Vector of entities to remove for next frame
	unsigned int m_totalEntities = 0; //int counting up and used as an ID for entities

	std::shared_ptr<Entity> m_player;


	std::default_random_engine m_randomEngine;

	std::uniform_int_distribution<int> m_randomInt;
	std::uniform_real_distribution<float> m_randomFloat;

	unsigned int m_timeSinceSpawn = spawntime - 30;

public:

	bool lifespanCalc = true;
	bool spawning = true;
	int spawntime = 120;

	EntityManager();
	~EntityManager();

	//Entity Management
	void update();
	std::shared_ptr<Entity> addEntity(std::shared_ptr<Entity>& ptr);
	std::shared_ptr<Entity> addToWaitList(const std::string& tag);
	void deletEntity(std::shared_ptr<Entity>&);
	EntityVec& getEntities();
	EntityVec& getEntities(std::string tag);

	//Entity Spawning
	void spawnEnemy();
	void spawnMiniEnemy();
	void spawnBullet(sf::Vector2i targetPos);
	std::shared_ptr<Entity> spawnPlayer(float posX, float posY, float size, float colRad, float speed, int r, int g, int b,
		int outR, int outG, int outB, float outThick, int verts);
	void resetPlayer();

	void switchLifespanCalc();

	//Random Generation
	int getDtEpoch();
	void initRandomEngine();
	void randomizeInt(int min, int max);
	void randomizeFloat(float min, float max);
	int randomI();
	float randomF();
};