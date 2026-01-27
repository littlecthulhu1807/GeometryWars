#include<iostream>

#include<SFML/Graphics.hpp>

#include"Game.h"
#include"Vec2.hpp"

Game::Game(){
    gameInit();
}

Game::~Game(){
}

void Game::gameInit(){

    m_sRender = SRender();
    m_sRender.sRenderInit(m_width, m_height);
    m_sPhysics = SPhysics();


    m_player = m_entityManager.addEntity("player");
    m_player->add<CShape>(50.0f, 10, sf::Color::Red);
    m_player->add<CTransform>(Vec2<float>(300.0f, 400.0f), Vec2<float>(0, 0));
    //m_player->add<CTransform>(Vec2<float>(300.0f, 400.0f), Vec2<float>(1.0f, 1.0f));
}

void Game::pollEvents()
{
    while (const auto event = m_sRender.getWindow().pollEvent()) {
        ImGui::SFML::ProcessEvent(m_sRender.getWindow(), *event);

        if (event->is<sf::Event::Closed>()) {
            m_sRender.getWindow().close();
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            //std::cout << keyPressed->code() << '\n';
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                m_sRender.getWindow().close();
            }
            if (keyPressed->scancode == sf::Keyboard::Scancode::R) {
                if (m_sRender.getRendering()) {
                    m_sRender.setRendering(false);
                }
                else {
                    m_sRender.setRendering(true);
                }
            }
            if (keyPressed->scancode == sf::Keyboard::Scancode::M) {
                if (m_sPhysics.getPhysicsCalc()) {
                    m_sPhysics.setPhysicsCalc(false);
                }
                else {
                    m_sPhysics.setPhysicsCalc(true);
                }
            }
        }
    }
}

void Game::run(){

    while (m_sRender.getWindow().isOpen()) {
        //Poll Events/ Input System
        pollEvents();

        //Collision

        //Move
        m_sPhysics.updateMovement(m_entityManager, m_width, m_height);

        //Imgui Updates
        //ImGui::SFML::Update(m_window, m_deltaClock.restart());
        //ImGui::Begin("Hello, world!");
        //ImGui::Button("Look at this pretty button");
        //ImGui::End();

        //Render
        //Iterate through Enteties and draw all enteties with Shape Component
        m_sRender.drawCalls(m_entityManager);
        //ImGui::SFML::Render(m_window);

        //Update EntityManager (Spawn/Delete)
    }

    ImGui::SFML::Shutdown();
    std::cin.get();
    
}

std::shared_ptr<Entity> Game::getPlayer(){
    return m_player;
}
