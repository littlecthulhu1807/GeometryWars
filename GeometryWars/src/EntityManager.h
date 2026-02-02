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


public:
	EntityManager();
	~EntityManager();

	void update();
	std::shared_ptr<Entity> addEntity(std::shared_ptr<Entity>& ptr);
	std::shared_ptr<Entity> addToWaitList(const std::string& tag);
	void deletEntity(std::shared_ptr<Entity>&);
	EntityVec& getEntities();
	EntityVec& getEntities(std::string tag);

	void spawnEnemy();
	void spawnBullet(sf::Vector2i targetPos);
	std::shared_ptr<Entity> spawnPlayer();

};