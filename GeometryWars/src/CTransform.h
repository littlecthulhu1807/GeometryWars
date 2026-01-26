#pragma once

#include"Component.h"
#include"Vec2.hpp"


class CTransform: public Component {
	Vec2<float> m_pos{};
	Vec2<float> m_velocity{};
	Vec2<float> m_scale{};
	float m_angle{};

public:
	CTransform();
	CTransform(Vec2<float> pos, Vec2<float> velocity);
	CTransform(Vec2<float> pos, Vec2<float> velocity, Vec2<float> scale, float angle);


	void setPos(Vec2<float> pos);
	void setVel(Vec2<float> velocity);
	void setScale(Vec2<float> scale);
	void setAngle(float angle);

	Vec2<float>& getPos();
	float getAngle();
	Vec2<float>& getVel();
	Vec2<float>& getScaler();

};