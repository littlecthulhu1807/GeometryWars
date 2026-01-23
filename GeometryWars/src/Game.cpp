#include<iostream>

#include"Game.h"

Game::Game(){
    gameInit();
}

Game::~Game(){
}

void Game::gameInit(){
    std::cout << "initGame\n";
    m_window = sf::RenderWindow(sf::VideoMode({ 640, 480 }), "Geometry Wars!");
    m_window.setFramerateLimit(60);
    ImGui::SFML::Init(m_window);
}

void Game::run(){
    std::cout << "runGame\n";
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);



    while (m_window.isOpen()) {
        //Poll Events/ Input System
        while (const auto event = m_window.pollEvent()) {
            ImGui::SFML::ProcessEvent(m_window, *event);

            if (event->is<sf::Event::Closed>()) {
                m_window.close();
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
        m_window.draw(shape);
        ImGui::SFML::Render(m_window);
        m_window.display();

        //Update EntityManager (Spawn/Delete)
    }

    ImGui::SFML::Shutdown();
}
