#pragma once

#include"EntityManager.h"
#include"SRender.h"
#include"SPhysics.h"

#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics.hpp>

class Game {

	unsigned int m_width = 1280;
	unsigned int m_height = 960;

	EntityManager m_entityManager;
	sf::Clock m_deltaClock;
	bool m_paused = false;
	SRender m_sRender;
	SPhysics m_sPhysics;

	std::shared_ptr<Entity> m_player;

	void pollEvents();

public:



	Game();
	~Game();

	void gameInit();
	void run();
	std::shared_ptr<Entity> getPlayer();
};
