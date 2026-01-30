#include"CTransform.h"

CTransform::CTransform(){}

CTransform::CTransform(Vec2<float> posIn, Vec2<float> velocityIn):
	pos(posIn),
	velocity(velocityIn){
}

CTransform::CTransform(Vec2<float> posIn, Vec2<float> velocityIn, Vec2<float> scaleIn, float angleIn):
	pos(posIn),
	velocity(velocityIn),
	scale(scaleIn),
	angle(angleIn){
}

void CTransform::setPos(Vec2<float> posIn){
	pos = posIn;
}

void CTransform::setVel(Vec2<float> velocityIn){
	velocity = velocityIn;
}

void CTransform::setScale(Vec2<float> scaleIn){
	scale = scaleIn;
}

void CTransform::setAngle(float angleIn){
	angle = angleIn;
}


