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

public:

	Entity(std::string tag, unsigned int id);

	template<typename T, typename... TArgs>
	T& add(TArgs&&... args);
	//template<typename T>
	//T& get();


	unsigned int id() const;
	bool isAlive() const;
	void destroy();
	const std::string& tag();

};

template<typename T, typename ...TArgs>
T& Entity::add(TArgs && ...args)
{
	for (auto& e : m_components) {
		if (e == T) {
			e.exists = true;
		}
	}
}
