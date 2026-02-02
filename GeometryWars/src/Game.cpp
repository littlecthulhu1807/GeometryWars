#include"Game.h"

Game::Game(){
    gameInit();
}

Game::~Game(){
}

void Game::gameInit(){

    m_sRender = SRender();
    m_sRender.sRenderInit(m_width, m_height);
    m_sPhysics = SPhysics();

    imGuiInit();

    m_player = m_entityManager.spawnPlayer();
    m_entityManager.spawnEnemy();
}

void Game::pollEvents()
{
    while (const auto event = m_sRender.getWindow().pollEvent()) {
        ImGui::SFML::ProcessEvent(m_sRender.getWindow(), *event);

        if (event->is<sf::Event::Closed>()) {
            m_sRender.getWindow().close();
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            //std::cout << (int)keyPressed->scancode << '\n';
            m_sInput.matchKeyInput(keyPressed->scancode, m_sRender, m_sPhysics, m_entityManager);
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyReleased>()) {
            //std::cout << (int)keyPressed->scancode << '\n';
            m_sInput.matchKeyRelease(keyPressed->scancode, m_entityManager);
        }
        else if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
            m_sInput.matchMouseInput(mouseEvent->button, mouseEvent->position, m_entityManager);
        }
    }
}

void Game::imGuiInit(){
    ImGui::SFML::Init(m_sRender.getWindow());
}

void Game::imGuiUpdate(){
    //std::cout << "Hello\n";
    ImGui::SFML::Update(m_sRender.getWindow(), m_deltaClock.restart());
    ImGui::Begin("Geometry Wars Control Board");
    if (ImGui::BeginTabBar("TabBar")) {
        if (ImGui::BeginTabItem("Systems")) {
            //execute Tab Content
            ImGui::Text("Some Text");
            ImGui::Checkbox("Movement", &m_sPhysics.physicsCalc);
            //ImGui::Checkbox("Lifespan", &m_sPhysics.m_physicsCalc);
            //ImGui::Checkbox("Collision", &m_sPhysics.m_physicsCalc);
            //ImGui::Checkbox("Spawning", &m_sPhysics.m_physicsCalc);
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Entity")) {
            //execute Tab Content
            ImGui::Text("Some Text2");
            if (ImGui::CollapsingHeader("Entity by Tag")) {
                if (ImGui::CollapsingHeader("Player")) {
                    for (auto& e : m_entityManager.getEntities("player")) {
                        std::string btnTxT = "D##D" + std::to_string(e->id());
                        ImGui::Text(e->tag().c_str());
                        ImGui::SameLine();
                        ImGui::Text("%d", e->id());
                        ImGui::SameLine();
                        if (ImGui::Button(btnTxT.c_str())) {
                            std::cout << btnTxT << '\n';
                        };
                        ImGui::SetItemTooltip("Delete Entity");
                    }

                }
                if (ImGui::CollapsingHeader("Bullets")) {
                    for (auto& e : m_entityManager.getEntities("bullet")) {
                        std::string btnTxT = "D##D" + std::to_string(e->id());
                        ImGui::Text(e->tag().c_str());
                        ImGui::SameLine();
                        ImGui::Text("%d", e->id());
                        ImGui::SameLine();
                        if (ImGui::Button(btnTxT.c_str())) {
                            std::cout << btnTxT << '\n';
                        };
                        ImGui::SetItemTooltip("Delete Entity");
                    }

                }
                if (ImGui::CollapsingHeader("Enemies")) {
                    for (auto& e : m_entityManager.getEntities("enemy")) {
                        std::string btnTxT = "D##D" + std::to_string(e->id());
                        ImGui::Text(e->tag().c_str());
                        ImGui::SameLine();
                        ImGui::Text("%d", e->id());
                        ImGui::SameLine();
                        if (ImGui::Button(btnTxT.c_str())) {
                            std::cout << btnTxT << '\n';
                        };
                        ImGui::SetItemTooltip("Delete Entity");
                    }

                }
                
            }
            if (ImGui::CollapsingHeader("All Entities")) {
                for (auto& e : m_entityManager.getEntities()) {
                    std::string btnTxT = "D##D" + std::to_string(e->id());
                    ImGui::Text(e->tag().c_str());
                    ImGui::SameLine();
                    ImGui::Text("%d", e->id());
                    ImGui::SameLine();
                    if (ImGui::Button(btnTxT.c_str())) {
                        std::cout << btnTxT << '\n';
                    };
                    ImGui::SetItemTooltip("Delete Entity");
                }
                
            }
            ImGui::EndTabItem();
        }
    }
    ImGui::EndTabBar();
    ImGui::End();
    
}

void Game::run(){

    while (m_sRender.getWindow().isOpen()) {
        //Poll Events/ Input System
        pollEvents();

        //Move
        m_sPhysics.updateMovement(m_entityManager, m_width, m_height);

        //Collision
        m_sCollision.checkCollision();

        //Imgui Updates
        imGuiUpdate();

        //Render
        //Iterate through Enteties and draw all enteties with Shape Component
        m_sRender.drawCalls(m_entityManager);
        ImGui::SFML::Render(m_sRender.getWindow());
        m_sRender.drawDisplay();

        //Update EntityManager (Spawn/Delete)
        m_entityManager.update();
    }

    ImGui::SFML::Shutdown();
    std::cin.get();
    
}

std::shared_ptr<Entity> Game::getPlayer(){
    return m_player;
}
