#pragma once
#include"Component.h"

class CCollision : public Component {
public:
	CCollision();
	CCollision(float radiusIn);
	float radius{};
};