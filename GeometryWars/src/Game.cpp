#include"Game.h"

Game::Game(){
    gameInit();
}

Game::~Game(){
}

void Game::gameInit(){

    m_configReader = ConfigReader();
    if (m_configReader.readData("config/Config.txt")) {}
    else
        std::cout << "ERROR FAILED TO LOAD CONFIG!";

    m_width = m_configReader.windowData.width;
    m_height = m_configReader.windowData.height;



    m_sRender = SRender();
    m_sRender.sRenderInit(m_width, m_height, m_configReader.windowData.frameLimit);
    m_sPhysics = SPhysics();

    imGuiInit();
    m_player = m_entityManager.spawnPlayer(
        m_width/2, m_height/2, m_configReader.playerData.shapeRadius, m_configReader.playerData.collisionRadius, m_configReader.playerData.speed, m_configReader.playerData.r, m_configReader.playerData.g,
        m_configReader.playerData.b, m_configReader.playerData.oR, m_configReader.playerData.oG, m_configReader.playerData.oB, m_configReader.playerData.outlineThickness, m_configReader.playerData.shapeVertices
    );

    if (!m_mainFont.openFromFile(m_configReader.fontData.filePath))
    {
        std::cout << "COULD NOT LOAD FONT " << m_configReader.fontData.filePath << '\n';
    }
    m_scoreText.setFont(m_mainFont);
    m_scoreText.setString(std::to_string(m_score));
    m_scoreText.setCharacterSize(m_configReader.fontData.size);
    m_scoreText.setFillColor(sf::Color({ uint8_t(m_configReader.fontData.r), uint8_t(m_configReader.fontData.g), uint8_t(m_configReader.fontData.b)}));
    m_scoreText.setPosition({ 0,0 });
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
            if (!ImGui::GetIO().WantCaptureMouse) { //only capture mouse outside of ImGUI windows
                m_sInput.matchMouseInput(mouseEvent->button, mouseEvent->position, m_entityManager);
            }
        }
    }
}

void Game::imGuiInit(){
    ImGui::SFML::Init(m_sRender.getWindow());
}

void Game::imGuiUpdate(){
    ImGui::SFML::Update(m_sRender.getWindow(), m_deltaClock.restart());
    ImGui::Begin("Geometry Wars Control Board");
    if (ImGui::BeginTabBar("TabBar")) {
        if (ImGui::BeginTabItem("Systems")) {
            //execute Tab Content
            ImGui::Text("Some Text");
            ImGui::Checkbox("Movement", &m_sPhysics.physicsCalc);
            ImGui::Checkbox("Lifespan", &m_entityManager.lifespanCalc);
            ImGui::Checkbox("Collision", &m_sCollision.collisionCalc);
            ImGui::Checkbox("Spawning", &m_entityManager.spawning);
            ImGui::SliderInt("SpawnRate", &m_entityManager.spawntime, 10, 240);
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
                            m_entityManager.deletEntity(e);
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
                            m_entityManager.deletEntity(e);
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
                            m_entityManager.deletEntity(e);
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
                        m_entityManager.deletEntity(e);
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

        //Collision & Score
        m_sCollision.checkCollision(m_score);
        m_scoreText.setString(std::to_string(m_score));

        //Imgui Updates
        imGuiUpdate();

        //Render
        //Iterate through Enteties and draw all enteties with Shape Component
        m_sRender.drawCalls(m_entityManager, m_scoreText);
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
