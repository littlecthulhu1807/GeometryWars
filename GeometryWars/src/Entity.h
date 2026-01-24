#pragma once

#include<string>
#include"CTransform.h"
#include"CCollision.h"
#include"CScore.h"
#include"CInput.h"
#include"CShape.h"
#include"CLifespan.h"


using components = std::tuple<
	typename CTransform,
	typename CCollision,
	typename CScore,
	typename CInput,
	typename CShape,
	typename CLifespan
>;

class Entity{
	components m_components;
	bool m_alive = true;
	std::string m_tag = std::string("default");
	unsigned int m_id;

public:

	Entity();
	~Entity();

	void add();
	Component get();
	unsigned int id() const;
	bool isAlive() const;
	void destroy();
	const std::string& tag();

};