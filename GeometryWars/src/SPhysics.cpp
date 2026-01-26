#include"SPhysics.h"

void SPhysics::updateMovement(EntityManager& entityM, int width, int height){
    if (m_physicsCalc) {
        for (auto& e : entityM.getEntities()) {
            if (e->get<CTransform>().exists) {
                auto& trans = e->get<CTransform>();
                auto& shape = e->get<CShape>();

                shape.getShape().setPosition({ trans.getPos().x + trans.getVel().x, trans.getPos().y + trans.getVel().y });
                trans.setPos({ shape.getShape().getPosition() });

                if (shape.getShape().getPosition().x >= width || shape.getShape().getPosition().x <= 0) {
                    std::cout << "width bound hit!\n";
                    trans.getVel().x = trans.getVel().x * -1;
                }
                if (shape.getShape().getPosition().y >= height || shape.getShape().getPosition().y <= 0) {
                    std::cout << "height bound hit!\n";
                    trans.getVel().y = trans.getVel().y * -1;
                }
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
