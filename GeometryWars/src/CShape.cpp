#include"CShape.h"

CShape::CShape(){}

CShape::CShape(float radius, int verts, sf::Color color) :
	radius(radius),
	verts(verts),
	color(color){

	shape = sf::CircleShape(radius);
	shape.setPointCount(verts);
	shape.setFillColor(color);
	shape.setOrigin(shape.getGeometricCenter());
}
