#pragma once

#include<string>


using components = std::tuple<>;


class Entity{
	components m_components;
	bool m_alive;
	int m_id;
	std::string m_tag;


public:
	Entity();
	~Entity();

};