#pragma once

#include"EntityManager.h"
#include"SRender.h"

#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics.hpp>

class Game {

	EntityManager m_entityManager;
	sf::RenderWindow m_window;
	sf::Clock m_deltaClock;
	bool m_paused = false;
	SRender m_sRender;

public:



	Game();
	~Game();

	void gameInit();
	void run();
};
