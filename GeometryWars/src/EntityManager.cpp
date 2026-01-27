#include"EntityManager.h"

//#include<memory>

EntityManager::EntityManager(){
	std::cout << "Created Entity Manager\n";
}

EntityManager::~EntityManager() {
	std::cout << "Deleted Entity Manager\n";
	m_EntityVec.clear();
	m_entityMap.clear();
	m_toAdd.clear();
	m_toRemove.clear();
}

void EntityManager::init(){
}

void EntityManager::update(){
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag){
	//create a new Entity object
	std::shared_ptr<Entity> ptr(new Entity(tag, m_totalEntities));

	//store it in a vector
	m_EntityVec.push_back(ptr);

	//store in a map of tag_entityVector
	m_entityMap[tag].push_back(ptr);

	m_totalEntities++;

	//return the shared pointer pointing to that entity
	return ptr;
}

void EntityManager::deletEntity(EntityVec& entity){
	
}

EntityVec& EntityManager::getEntities(){
	return m_EntityVec;
}

EntityVec& EntityManager::getEntities(std::string tag){
	return m_entityMap[tag];
}

void EntityManager::spawnEnemy(){
}

void EntityManager::spawnBullet(){
}
