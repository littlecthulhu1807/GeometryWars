#pragma once

#include<string>
#include<iostream>
#include<tuple>

#include"CTransform.h"
#include"CCollision.h"
#include"CScore.h"
#include"CInput.h"
#include"CShape.h"
#include"CLifespan.h"

//Forward declare EntityManager to set it as a friend, otherwise when just including it the template breaks... What the fuck?
class EntityManager;

using components = std::tuple<
	CTransform,
	//CCollision,
	//CScore,
	//CInput,
	CShape
	//CLifespan
>;

class Entity{
	components m_components;
	bool m_alive = true;
	std::string m_tag = std::string("default");
	unsigned int m_id = 0;

	Entity(std::string tag, unsigned int id);


public:
	friend class EntityManager;

	template<typename T, typename... TArgs>
	void add(TArgs&&... args);
	template<typename T>
	T& get();


	unsigned int id() const;
	bool isAlive() const;
	void destroy();
	const std::string& tag();

};

template<typename T, typename... TArgs>
void Entity::add(TArgs&&... mArgs) {
	auto& component = Entity::get<T>(m_components);
	component = T(std::forward<TArgs>(mArgs)...);
	component.exists = true;
}

template<typename T>
T& Entity::get() {
	return std::get<T>(m_components);
}
