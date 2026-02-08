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

void EntityManager::update(){
	//Update Lifespans
	if (lifespanCalc) {
		for (auto& e : m_EntityVec) {
			e->get<CLifespan>().updateLifespan();
			if (e->get<CLifespan>().lifespanLeft <= 0) {
				deletEntity(e);
			}
		}
	}
	//Add Entities in queque
	for (auto& e : m_toAdd) {
		addEntity(e);
	}
	m_toAdd.clear();
	//delete Entities in queque
	for (auto& e : m_toRemove) {
		m_EntityVec.erase(
			std::remove_if(m_EntityVec.begin(), m_EntityVec.end(),
				[&](const std::shared_ptr<Entity>& entity) {
					// Check if this entity is in m_toRemove
					return std::find(m_toRemove.begin(), m_toRemove.end(), entity) != m_toRemove.end();
				}),
			m_EntityVec.end()
		);

		m_entityMap[e->tag()].erase(
			std::remove_if(m_entityMap[e->tag()].begin(), m_entityMap[e->tag()].end(),
				[&](const std::shared_ptr<Entity>& entity) {
					// Check if this entity is in m_toRemove
					return std::find(m_toRemove.begin(), m_toRemove.end(), entity) != m_toRemove.end();
				}),
			m_entityMap[e->tag()].end()
		);
	}
	m_toRemove.clear();
}

std::shared_ptr<Entity> EntityManager::addEntity(std::shared_ptr<Entity>& ptr){
	//store it in a vector
	m_EntityVec.push_back(ptr);
	//store in a map of tag_entityVector
	m_entityMap[ptr->tag()].push_back(ptr);
	//return the shared pointer pointing to that entity
	return ptr;
}

std::shared_ptr<Entity> EntityManager::addToWaitList(const std::string& tag){
	std::shared_ptr<Entity> ptr(new Entity(tag, m_totalEntities));
	m_toAdd.push_back(ptr);
	m_totalEntities++;
	return ptr;
}

void EntityManager::deletEntity(std::shared_ptr<Entity>& entity){
	m_toRemove.push_back(entity);
}

EntityVec& EntityManager::getEntities(){
	return m_EntityVec;
}

EntityVec& EntityManager::getEntities(std::string tag){
	return m_entityMap[tag];
}








void EntityManager::spawnEnemy(){
	
	std::shared_ptr<Entity> tempEntity = addToWaitList("enemy");
	tempEntity->add<CTransform>(Vec2<float>(200.0f, 200.0f), Vec2<float>(5.0f, 5.0f));
	tempEntity->add<CCollision>(25.0f);
	tempEntity->add<CScore>(200);
	tempEntity->add<CShape>(50.0f, 5, sf::Color::Blue);
}

void  EntityManager::spawnMiniEnemy(){
	std::shared_ptr<Entity> tempEntity = addToWaitList("enemy");
	tempEntity->add<CTransform>(Vec2<float>(200.0f, 200.0f), Vec2<float>(5.0f, 5.0f));
	tempEntity->add<CCollision>(25.0f);
	tempEntity->add<CScore>(200);
	tempEntity->add<CShape>(50.0f, 5, sf::Color::Blue);
	tempEntity->add<CLifespan>(60);
}

void EntityManager::spawnBullet(sf::Vector2i targetPos){
	Vec2<float> target = Vec2<float>(targetPos.x, targetPos.y);
	Vec2<float> targetDirection = m_player->get<CTransform>().pos.distance(target).normalize().scale(15);
	std::shared_ptr<Entity> tempEntity = addToWaitList("bullet");
	tempEntity->add<CTransform>(m_player->get<CTransform>().pos, targetDirection);
	tempEntity->add<CCollision>(5.0f);
	tempEntity->add<CShape>(10.0f, 10, sf::Color::White);
	tempEntity->add<CLifespan>(120);
}

std::shared_ptr<Entity> EntityManager::spawnPlayer(float size, float colRad, float speed, int r, int g, int b,
	int outR, int outB, int outG, float outThick, int verts) {
	std::shared_ptr<Entity> tempEntity = addToWaitList("player");
	tempEntity->add<CShape>(50.0f, 10, sf::Color::Red);
	tempEntity->add<CCollision>(25.0f);
	tempEntity->add<CTransform>(Vec2<float>(300.0f, 400.0f), Vec2<float>(10.0f, 10.0f));
	tempEntity->add<CInput>();
	m_player = tempEntity;
	return tempEntity;
}

void EntityManager::resetPlayer(){
	m_player->get<CTransform>().setPos(Vec2<float>(300.0f, 400.0f));
	m_player->get<CShape>().shape.setPosition({ 300.0f, 400.0f });
}

void EntityManager::switchLifespanCalc(){
	if (lifespanCalc) {
		lifespanCalc = false;
	}
	else{
		lifespanCalc = true;
	}
}
