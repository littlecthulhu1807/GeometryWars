#pragma once

#include"EntityManager.h"
#include"SRender.h"
#include"SPhysics.h"
#include"SInput.h"
#include"SSpawner.h"
#include"SCollision.h"
#include"Vec2.hpp"

#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics.hpp>

#include<iostream>

class Game {

	unsigned int m_width = 1280;
	unsigned int m_height = 960;

	EntityManager m_entityManager;
	sf::Clock m_deltaClock;
	bool m_paused = false;
	SRender m_sRender;
	SPhysics m_sPhysics;
	SInput m_sInput;
	SSpawner m_sSpawner = SSpawner(m_entityManager);
	SCollision m_sCollision = SCollision(m_entityManager);

	sf::Font m_mainFont;
	sf::Text m_scoreText{ m_mainFont };

	std::shared_ptr<Entity> m_player;

	void pollEvents();
	void imGuiInit();
	void imGuiUpdate();

public:



	Game();
	~Game();

	void gameInit();
	void run();
	std::shared_ptr<Entity> getPlayer();
};
