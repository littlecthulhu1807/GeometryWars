#include"SSpawner.h"

SSpawner::SSpawner(EntityManager& entityManager):
m_entityManager(entityManager){
	m_player = player();
}

std::shared_ptr<Entity> SSpawner::player(){
	return std::shared_ptr<Entity>();
}

void SSpawner::enemy(){
}

void SSpawner::miniEnemy(){
}

void SSpawner::randomizeInt(int min, int max){
}

void SSpawner::randomizeFloat(float min, float max){
}

int SSpawner::randomI(){
	return 0;
}

float SSpawner::randomF(){
	return 0.0f;
}

