#include"CShape.h"

CShape::CShape(){}

CShape::CShape(float radius, int verts, sf::Color color) :
	m_radius(radius),
	m_verts(verts),
	m_color(color){

	m_shape = sf::CircleShape(m_radius);
	m_shape.setPointCount(m_verts);
	m_shape.setFillColor(m_color);
	m_shape.setOrigin(m_shape.getGeometricCenter());
}

sf::CircleShape& CShape::getShape()
{
	return m_shape;
}
