#pragma once

#include"Entity.h"

#include<string>
#include<vector>
#include<map>



class EntityManager{

	std::vector<Entity> m_EntityVec; //std::Vector of Enteties
	std::map<Entity, std::string> m_entityMap; //std::map of entities with tags
	std::vector<Entity> m_toAdd; //Std::Vector of entities to add for next frame
	bool m_toRemove; //Std::Vector of entities to remove for next frame
	int m_totalEntities; //int counting up and used as an ID for entities


public:
	EntityManager();
	~EntityManager();

	void init();
	void update();
	void addEntity();
	void deletEntity();
	void getEntities();
	void getEntities(std::string tag);

};