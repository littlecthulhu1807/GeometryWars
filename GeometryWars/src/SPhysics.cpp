#include"SPhysics.h"

#include<iostream>

void SPhysics::updateMovement(EntityManager& entityM, int height, int width){
    if (m_physicsCalc) {
        for (auto& e : entityM.getEntities()) {
            if (e->get<CTransform>().exists) {
                auto& trans = e->get<CTransform>();
                auto& shape = e->get<CShape>();

                if (shape.getShape().getPosition().x >= width || shape.getShape().getPosition().x <= 0) {
                    std::cout << "width bound hit!\n";
                    trans.getVel().x *= -1;
                }
                if (shape.getShape().getPosition().y >= height || shape.getShape().getPosition().y <= 0) {
                    std::cout << "height bound hit!\n";
                    trans.getVel().y *= -1;
                }

                shape.getShape().setPosition({ trans.getPos().x + trans.getVel().x, trans.getPos().y + trans.getVel().x });
                trans.setPos({ shape.getShape().getPosition()});
                //std::cout << "move\n";
            }
        }
    }
}

void SPhysics::setPhysicsCalc(bool setP){
	m_physicsCalc = setP;
}

bool SPhysics::getPhysicsCalc(){
	return m_physicsCalc;
}
