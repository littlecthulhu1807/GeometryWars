#include"SRender.h"

SRender::SRender(){}

void SRender::sRenderInit(unsigned int width, unsigned int height, unsigned int frameLimit){
    m_window = sf::RenderWindow(sf::VideoMode({ width, height }), "Geometry Wars!");
    m_window.setFramerateLimit(frameLimit);
}

void SRender::drawCalls(EntityManager& entityM, sf::Text scoreText){
    if (m_rendering){
        m_window.clear();
        for (auto& e : entityM.getEntities()) {
            if (e->get<CShape>().exists) {
                m_window.draw(e->get<CShape>().shape);
            }
        }
        m_window.draw(scoreText);
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
