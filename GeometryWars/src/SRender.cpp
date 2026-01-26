#include"SRender.h"

SRender::SRender(){
}

void SRender::sRenderInit(unsigned int width, unsigned int height){
    m_window = sf::RenderWindow(sf::VideoMode({ width, height }), "Geometry Wars!");
    m_window.setFramerateLimit(60);
    ImGui::SFML::Init(m_window);
}

void SRender::drawCalls(EntityManager& entityM){
    if (m_rendering){
        m_window.clear();
        for (auto& e : entityM.getEntities()) {
            if (e->get<CShape>().exists) {
                m_window.draw(e->get<CShape>().getShape());
            }
        }
        m_window.display();
    }
}   

void SRender::setRendering(bool rendering){
    m_rendering = rendering;
}

bool SRender::getRendering()
{
    return m_rendering;
}
