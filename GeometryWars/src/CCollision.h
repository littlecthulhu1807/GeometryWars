#pragma once


#include"Component.h"

class CCollision : public Component {
public:
	CCollision();
	~CCollision();

private:
	float radius;
};