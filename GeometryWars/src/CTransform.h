#pragma once

#include"Component.h"
#include"Vec2.hpp"


class CTransform: public Component {
public:
	CTransform();
	~CTransform();

private:
	Vec2<float> pos;
	Vec2<float> velocity;
	Vec2<float> scale;
	float angle;
};