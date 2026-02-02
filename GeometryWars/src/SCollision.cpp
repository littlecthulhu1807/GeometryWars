#include"SCollision.h"

SCollision::SCollision(EntityManager& entityManager)
	:m_entityManager(entityManager){}

void SCollision::checkCollision()
{
	for (auto b : m_entityManager.getEntities("bullet")) {
		for (auto e : m_entityManager.getEntities("enemy")) {
			if ((b->get<CCollision>().radius + e->get<CCollision>().radius) <= abs(b->get<CTransform>().pos.distance(e->get<CTransform>().pos).lenght()))
			{
				m_entityManager.deletEntity(b);
				m_entityManager.deletEntity(e);
			}
		}
	}
}
