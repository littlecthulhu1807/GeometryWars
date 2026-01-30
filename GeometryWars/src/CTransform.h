#pragma once

#include"Component.h"
#include"Vec2.hpp"


class CTransform: public Component {
	

public:
	Vec2<float> pos{};
	Vec2<float> velocity{};
	Vec2<float> scale{};
	float angle{};

	CTransform();
	CTransform(Vec2<float> pos, Vec2<float> velocity);
	CTransform(Vec2<float> pos, Vec2<float> velocity, Vec2<float> scale, float angle);


	void setPos(Vec2<float> pos);
	void setVel(Vec2<float> velocity);
	void setScale(Vec2<float> scale);
	void setAngle(float angle);
};