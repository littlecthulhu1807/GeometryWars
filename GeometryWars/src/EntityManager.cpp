#include"EntityManager.h"

#include<memory>

EntityManager::EntityManager(){
	std::cout << "Created Entity Manager\n";
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

void EntityManager::deletEntity(EntityVec&){
}

//EntityVec& EntityManager::getEntities(){
//	// TODO: insert return statement here
//}

//EntityVec& EntityManager::getEntities(std::string tag){
//	// TODO: insert return statement here
//}
