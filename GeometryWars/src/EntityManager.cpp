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
	
	std::shared_ptr<Entity> tempEntity = addEntity("enemy");
	tempEntity->add<CTransform>(Vec2<float>(200.0f, 200.0f), Vec2<float>(15.0f, 15.0f));
	//tempEntity->add<CCollision>();
	//tempEntity->add<CScore>();
	tempEntity->add<CShape>(50.0f, 5, sf::Color::Blue);
	//tempEntity->add<CLifespan>();
	

}

void EntityManager::spawnBullet(){
	/*
	std::shared_ptr<Entity> tempEntity = addEntity("bullet");
	tempEntity->add<CTransform>();
	tempEntity->add<CCollision>();
	tempEntity->add<CScore>();
	tempEntity->add<CShape>();
	tempEntity->add<CLifespan>();
	*/
}

std::shared_ptr<Entity> EntityManager::spawnPlayer(){
	std::shared_ptr<Entity> tempEntity = addEntity("player");
	tempEntity->add<CShape>(50.0f, 10, sf::Color::Red);
	tempEntity->add<CTransform>(Vec2<float>(300.0f, 400.0f), Vec2<float>(10.0f, 10.0f));
	tempEntity->add<CInput>();
	return tempEntity;
}
