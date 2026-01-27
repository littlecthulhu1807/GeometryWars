#pragma once


#include"Component.h"

class CCollision : public Component {
public:
	CCollision();

private:
	float radius{};
};