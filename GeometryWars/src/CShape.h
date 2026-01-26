#pragma once

#include"Component.h"

#include<SFML/Graphics.hpp>

class CShape : public Component {
	sf::CircleShape m_shape{};
	float m_radius{};
	int m_verts{};
	sf::Color m_color{};

public:

	CShape();
	CShape(float radius, int verts, sf::Color color);

	sf::CircleShape& getShape();
};