#include<iostream>

#include<SFML/Graphics.hpp>

#include"Game.h"
#include"Component.h"
#include"CShape.h"
#include"CTransform.h"
#include"Vec2.hpp"

Game::Game(){
    gameInit();
}

Game::~Game(){
}

void Game::gameInit(){
    m_entityManager.addEntity("player")->add<Component, CShape, CTransform>(CShape(), CTransform());
        //->add<Component>();
    //add<Component, CShape, CTransform>(CShape(50.0f, 8, sf::Color::Red), CTransform({300, 300}, {0, 0}));
    m_entityManager.addEntity("enemy");
    m_entityManager.addEntity("enemy");

    m_window = sf::RenderWindow(sf::VideoMode({ 640, 480 }), "Geometry Wars!");
    m_window.setFramerateLimit(60);
    ImGui::SFML::Init(m_window);

    m_sRender.sRenderInit();
}

void Game::run(){

    while (m_window.isOpen()) {
        //Poll Events/ Input System
        while (const auto event = m_window.pollEvent()) {
            ImGui::SFML::ProcessEvent(m_window, *event);

            if (event->is<sf::Event::Closed>()) {
                m_window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
                    m_window.close();
                }
            }
        }

        //Collision

        //Move


        //Imgui Updates
        ImGui::SFML::Update(m_window, m_deltaClock.restart());
        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();

        //Render
        m_window.clear();
        //Iterate through Enteties and draw all enteties with Shape Component
        //for (auto& e : m_entityManager.getEntities()) {
        //    if (e->get<CShape>().exists) {
        //        std::cout << "draw\n";
        //        m_window.draw(e->get<CShape>().m_shape);
        //    }
        //}
        ImGui::SFML::Render(m_window);
        m_window.display();

        //Update EntityManager (Spawn/Delete)
    }

    ImGui::SFML::Shutdown();
    std::cin.get();
    
}
