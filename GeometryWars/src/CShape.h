#pragma once

#include"Component.h"

#include<SFML/Graphics.hpp>

class CShape : public Component {
	

public:

	sf::CircleShape shape{};
	float radius{};
	int verts{};
	sf::Color color{};

	CShape();
	CShape(float radius, int verts, sf::Color color);
};