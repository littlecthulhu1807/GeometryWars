#include"SPhysics.h"

void SPhysics::updateMovement(EntityManager& entityM, int width, int height){
    if (m_physicsCalc) {
        updatePlayer(entityM);
        updateEntityType(entityM, "bullet", width, height);
        updateEntityType(entityM, "enemy", width, height);
    }
}

void SPhysics::setPhysicsCalc(bool setP){
	m_physicsCalc = setP;
}

bool SPhysics::getPhysicsCalc(){
	return m_physicsCalc;
}

void SPhysics::updatePlayer(EntityManager& entityM){
    for (auto& e : entityM.getEntities("player")) {
        if (e->get<CTransform>().exists) {
            auto& trans = e->get<CTransform>();
            auto& shape = e->get<CShape>();

            shape.getShape().setPosition({ trans.getPos().x , trans.getPos().y });
            trans.setPos({ shape.getShape().getPosition() });
            shape.getShape().setRotation(shape.getShape().getRotation() + sf::degrees(5.0f));
        }
    }
}

void SPhysics::updateEntityType(EntityManager& entityM, std::string entityKey, int width, int height){
    for (auto& e : entityM.getEntities("enemy")) {
        if (e->get<CTransform>().exists) {
            auto& trans = e->get<CTransform>();
            auto& shape = e->get<CShape>();

            shape.getShape().setPosition({ trans.getPos().x + trans.getVel(), trans.getPos().y + trans.getVel() });
            trans.setPos({ shape.getShape().getPosition() });

            if (shape.getShape().getPosition().x >= width || shape.getShape().getPosition().x <= 0) {
                std::cout << "width bound hit!\n";
                trans.getVel() = trans.getVel() * -1;
            }
            if (shape.getShape().getPosition().y >= height || shape.getShape().getPosition().y <= 0) {
                std::cout << "height bound hit!\n";
                trans.getVel() = trans.getVel() * -1;
            }
        }
    }
}
