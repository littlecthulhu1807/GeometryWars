#include"CTransform.h"

CTransform::CTransform(){}

CTransform::CTransform(Vec2<float> pos, Vec2<float> velocity):
	m_pos(pos),
	m_velocity(velocity){
}

CTransform::CTransform(Vec2<float> pos, Vec2<float> velocity, Vec2<float> scale, float angle):
	m_pos(pos),
	m_velocity(velocity),
	m_scale(scale),
	m_angle(angle){
}

void CTransform::setPos(Vec2<float> pos){
	m_pos = pos;
}

void CTransform::setVel(Vec2<float> velocity){
	m_velocity = velocity;
}

void CTransform::setScale(Vec2<float> scale){
	m_scale = scale;
}

void CTransform::setAngle(float angle){
	m_angle = angle;
}


