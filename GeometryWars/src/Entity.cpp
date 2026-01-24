#include"Entity.h"

Entity::Entity(std::string tag, unsigned int id):
m_tag(tag),
m_id(id){
	std::cout << "Created object: " << this->tag().c_str() << " With id: " << this->id() << '\n';
}

unsigned int Entity::id() const{
	return m_id;
}

bool Entity::isAlive() const
{
	return m_alive;
}

void Entity::destroy(){
}

const std::string& Entity::tag(){
	return m_tag;
}
