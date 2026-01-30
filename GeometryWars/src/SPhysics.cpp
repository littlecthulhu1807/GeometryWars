#include"SPhysics.h"

void SPhysics::updateMovement(EntityManager& entityM, int width, int height){
    updatePlayer(entityM);
    updateBullet(entityM);
    updateEnemyType(entityM, width, height);
}

void SPhysics::updatePlayer(EntityManager& entityM){
    for (auto& e : entityM.getEntities("player")) {
        if (e->get<CTransform>().exists) {
            auto& tempTrans = e->get<CTransform>();
            auto& tempShape = e->get<CShape>();
            auto& tempInput = e->get<CInput>();

            if (physicsCalc) {
                tempShape.shape.setPosition({ tempTrans.pos.x , tempTrans.pos.y });
                tempTrans.setPos({ tempShape.shape.getPosition() });

                //Up
                if (tempInput.up && !tempInput.right && !tempInput.left) {
                    tempShape.shape.setPosition({ tempTrans.pos.x, tempTrans.pos.y - tempTrans.velocity.y });
                    tempTrans.setPos({ tempShape.shape.getPosition() });
                }
                if (tempInput.up && tempInput.right && !tempInput.left) {
                    tempShape.shape.setPosition({ tempTrans.pos.x + tempTrans.velocity.lenght()/2, tempTrans.pos.y - tempTrans.velocity.lenght()/2 });
                    tempTrans.setPos({ tempShape.shape.getPosition() });
                }
                if (tempInput.up && !tempInput.right && tempInput.left) {
                    tempShape.shape.setPosition({ tempTrans.pos.x - tempTrans.velocity.lenght()/2, tempTrans.pos.y - tempTrans.velocity.lenght()/2 });
                    tempTrans.setPos({ tempShape.shape.getPosition() });
                }
                //Right only
                if (tempInput.right && !tempInput.up && !tempInput.down) {
                    tempShape.shape.setPosition({ tempTrans.pos.x + tempTrans.velocity.x, tempTrans.pos.y });
                    tempTrans.setPos({ tempShape.shape.getPosition() });
                }
                //Down
                if (tempInput.down && !tempInput.right && !tempInput.left) {
                    tempShape.shape.setPosition({ tempTrans.pos.x, tempTrans.pos.y + tempTrans.velocity.y });
                    tempTrans.setPos({ tempShape.shape.getPosition() });
                }
                if (tempInput.down && !tempInput.right && tempInput.left) {
                    tempShape.shape.setPosition({ tempTrans.pos.x - tempTrans.velocity.lenght()/2, tempTrans.pos.y + tempTrans.velocity.lenght()/2 });
                    tempTrans.setPos({ tempShape.shape.getPosition() });
                }
                if (tempInput.down && tempInput.right && !tempInput.left) {
                    tempShape.shape.setPosition({ tempTrans.pos.x + tempTrans.velocity.lenght()/2, tempTrans.pos.y + tempTrans.velocity.lenght()/2 });
                    tempTrans.setPos({ tempShape.shape.getPosition() });
                }
                //left only
                if (tempInput.left && !tempInput.up && !tempInput.down) {
                    tempShape.shape.setPosition({ tempTrans.pos.x - tempTrans.velocity.x, tempTrans.pos.y });
                    tempTrans.setPos({ tempShape.shape.getPosition() });
                }
                

            }


            
            tempShape.shape.setRotation(tempShape.shape.getRotation() + sf::degrees(2.0f));
        }
    }
}

void SPhysics::updateEnemyType(EntityManager& entityM, int width, int height){
    for (auto& e : entityM.getEntities("enemy")) {
        if (e->get<CTransform>().exists) {
            auto& trans = e->get<CTransform>();
            auto& tempshape = e->get<CShape>();

            if (physicsCalc){
                tempshape.shape.setPosition({ trans.pos.x + trans.velocity.x, trans.pos.y + trans.velocity.y });
                trans.setPos({ tempshape.shape.getPosition() });
                

                if (tempshape.shape.getPosition().x >= width || tempshape.shape.getPosition().x <= 0) {
                    trans.velocity.x = trans.velocity.x * -1;
                }
                if (tempshape.shape.getPosition().y >= height || tempshape.shape.getPosition().y <= 0) {
                    trans.velocity.y = trans.velocity.y * -1;
                }
            }
            tempshape.shape.setRotation(tempshape.shape.getRotation() + sf::degrees(2.0f));
        }
    }
}

void SPhysics::updateBullet(EntityManager& entityM) {
    for (auto& e : entityM.getEntities("bullet")) {
        if (e->get<CTransform>().exists) {
            auto& trans = e->get<CTransform>();
            auto& tempshape = e->get<CShape>();

            if (physicsCalc) {
                tempshape.shape.setPosition({ trans.pos.x + trans.velocity.x, trans.pos.y + trans.velocity.y });
                trans.setPos({ tempshape.shape.getPosition() });
            }
            tempshape.shape.setRotation(tempshape.shape.getRotation() + sf::degrees(2.0f));
        }
    }
}
