#include"SRender.h"

SRender::SRender(){
}

void SRender::sRenderInit(unsigned int width, unsigned int height){
    m_window = sf::RenderWindow(sf::VideoMode({ width, height }), "Geometry Wars!");
    m_window.setFramerateLimit(60);
}

void SRender::drawCalls(EntityManager& entityM){
    if (m_rendering){
        m_window.clear();
        for (auto& e : entityM.getEntities()) {
            if (e->get<CShape>().exists) {
                //std::cout << e->tag().c_str() <<'\n';
                m_window.draw(e->get<CShape>().getShape());
            }
        }
    }
}

void SRender::drawDisplay(){
    m_window.display();
}

void SRender::setRendering(bool rendering){
    m_rendering = rendering;
}

bool SRender::getRendering()
{
    return m_rendering;
}
