#include"SCollision.h"

SCollision::SCollision(EntityManager& entityManager)
	:m_entityManager(entityManager){}

void SCollision::checkCollision(unsigned int& score)
{
	for (auto b : m_entityManager.getEntities("bullet")) {
		for (auto e : m_entityManager.getEntities("enemy")) {
			if ((b->get<CCollision>().radius + e->get<CCollision>().radius) >= abs(b->get<CTransform>().pos.distance(e->get<CTransform>().pos).lenght()))
			{
				//std::cout << "collision for radius: " << (b->get<CCollision>().radius + e->get<CCollision>().radius) << " at lenght: " << abs(b->get<CTransform>().pos.distance(e->get<CTransform>().pos).lenght()) << '\n';
				score = score + addScore(e);
				m_entityManager.deletEntity(b);
				m_entityManager.deletEntity(e);
			}
		}
	}

	for (auto e : m_entityManager.getEntities("enemy")) {
		for (auto p : m_entityManager.getEntities("player")) {
			if ((e->get<CCollision>().radius + p->get<CCollision>().radius) >= abs(e->get<CTransform>().pos.distance(p->get<CTransform>().pos).lenght()))
			{
				m_entityManager.resetPlayer();
			}
		}
	}
}

unsigned int SCollision::addScore(std::shared_ptr<Entity> entity){
	return entity->get<CScore>().score;
}
